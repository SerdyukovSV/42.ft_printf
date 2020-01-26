#include "ft_printf.h"

char    *ft_strrev(char *src)
{
    char *dst;
    int i;
    int k;

    i = 0;
    k = 0;
    while (src[k])
        k++;
    if (!(dst = (char *)malloc(sizeof(char)* k + 1)))
        return (NULL);
    while (--k >= 0)
        dst[i++] = src[k];
    dst[i] = '\0';
    return (dst);
}

long double  ft_power(long double nbr, int n)
{
    if (n == 0)
        return (1);
    if (n < 0)
        return (ft_power(1.0/nbr, -n));
    return (nbr * ft_power(nbr, n - 1));
}

char *get_bin(unsigned char c)
{
    int i;
    char *tmp;

    i = 0;
    if (!(tmp = (char *)malloc(sizeof(char)* 9)))
        return (NULL);
    while (c != 0)
    {
        tmp[i] = "01"[c % 2];
        c /= 2;
        i++;
    }
    while (i != 8)
        tmp[i++] = '0';
    tmp[i] = '\0';
    tmp = ft_strrev(tmp);
    return (tmp);
}

int get_exponent(char *exp, int len, int correct)
{
    int res;

    res = 0;
    while (len >= 0)
    {
        res += (*exp - 48) * (ft_power(2, len));
        exp += 1;
        len -= 1;
    }
    return (res - correct);
}

int *divide_bigint(int *mant, int exp, int *len)
{
    
    int i;
    int mod;
    int mod2;
    int tmp[*len];

    if (exp < 0)
    {
        i = 0;
        mod = (mant[i] % 2 > 0) ? 5 : 0;
        mant[i] = mant[i] / 2;
        while (++i < *len)
        {
            if (mant[i] != 46)
            {
                mod2 = (mant[i] % 2 > 0) ? 5 : 0;
                mant[i] = (mant[i] / 2) + mod;
                mod = mod2;
            }
            if (mod > 0 && (i == (*len-1)))
            {
                i = -1;
                while (++i < *len)
                    tmp[i] = mant[i];
                tmp[i] = mod;
                *len += 1;
                return (divide_bigint(tmp, exp + 1, len));
            }
        }
        return (divide_bigint(mant, exp + 1, len));
    }
    return (mant);
}

int *sort_bigint(int *mant, int *len)
{
    int             *tmp;
    int             i;
    int             k;

    i = *len;
    k = 0;
    while (--i >= 0)
    {
        if (mant[i] != 46 && mant[i] > 9 && (i - 1) >= 0)
        {
            (mant[i - 1] == 46) ? (mant[i - 2] += mant[i] / 10) : (mant[i - 1] += mant[i] / 10);
            mant[i] = mant[i] % 10;
        }
        else if (mant[i] != 46 && mant[i] > 9 && (i - 1) < 0)
        {
            if (!(tmp = (int *)malloc(sizeof(int) * (*len) + 1)))
                return (0);
            tmp[k++] = mant[i] / 10;
            tmp[k++] = mant[i] % 10;
            i = 0;
            while (++i < (*len))
                tmp[k++] = (i == (*len -1)) ? 0 : mant[i];
            *len += 1;
            free(mant);
            mant = tmp;
            i = *len;
            k = 0;
        }
    }
    return (mant);
}

int *multiply_bigint(int *mant, int exp, int *len)
{
    int i;

    while (exp > 0)
    {
        i = 0;
        while (i < *len)
        {
            if (mant[i] == 46)
                i++;
            mant[i] *= 2;
            i++;
        }
        mant = sort_bigint(mant, len);
        exp -= 1;
    }
    return (mant);
}

int *get_mantisa(char *mant, int *len, int *bin_dec)
{
    int i;
    int k;
    int tmp;
    long double res[64];

    i = -1;
    k = 0;
    while (*mant != '\0' && i >= -64)
    {
        res[k++] = (*mant - 48) * (ft_power(2, i--));
        mant += 1;
    }
    if (!(bin_dec = (int *)malloc(sizeof(int) * (++i * -1)+2)))
        return (NULL);
    bin_dec[0] = 1;
    bin_dec[1] = 46;
    *len = (i* - 1) + 2;
    i = -1;
    while (++i < (*len - 2))
    {
        k = 2;
        while (res[i])
        {
            res[i] *= 10;
            tmp = (int)res[i];
            bin_dec[k++] += tmp;
            res[i] -= (long double)tmp;
        }
        bin_dec = sort_bigint(bin_dec, &k);
    }
    return (bin_dec);
}

/*
 0    111111111111110 1111111111111111111111111111111111111111111111111111111111111111
1bit        15bit                                    64bit
*/

// (-1)Sign × (1 + Mantissa) × 2(Exponent adjusted);

static char *ft_dectostr(int *arr, int sign, int len)
{
    int i;
    int k;
    char *str;

    if (!(str = (char *)malloc(sizeof(char) * len+1+sign)))
        return (0);
    k = -1;
    i = 0;
    (sign == 1) ? str[i++] = 45 : 0;
    while (++k < len)
        str[i++] = (arr[k] == 46) ? 46 : arr[k] + 48;
    str[i] = '\0';
    return (str);
}

int printf_f(double d, int len)
{
    int     exp;
    int     *bin_dec;
    char    *str;
    unsigned char str_mem[len + 1];

    if (!(str = (char *)malloc(sizeof(char) * 100)))
        return (0);
    ft_memcpy(str_mem, &d, len);
    while (--len >= 0)
        str = ft_strcat(str, get_bin(str_mem[len]));
    exp = get_exponent(str + 1, 10, 1023);
    bin_dec = get_mantisa(str + 12, &len, bin_dec);
    (exp >= 0) ? bin_dec = multiply_bigint(bin_dec, exp, &len) : 0;
    (exp <  0) ? bin_dec = divide_bigint(bin_dec, exp, &len) : 0;
    str = ft_dectostr(bin_dec, (*str == '1' ? 1 : 0), len);
    ft_putstr(str);
    return (len);
}

int printf_lf(long double d, int len)
{
    int     exp;
    int     *bin_dec;
    char    *str;
    unsigned char str_mem[len + 1];

    if (!(str = (char *)malloc(sizeof(char) * 100)))
        return (0);
    ft_memcpy(str_mem, &d, len);
    while (--len >= 0)
        str = ft_strcat(str, get_bin(str_mem[len]));
    exp = get_exponent(str + 1, 14, 16383);
    bin_dec = get_mantisa(str + 17, &len, bin_dec);
    (exp >= 0) ? bin_dec = multiply_bigint(bin_dec, exp, &len) : 0;
    (exp <  0) ? bin_dec = divide_bigint(bin_dec, exp, &len) : 0;
    str = ft_dectostr(bin_dec, (*str == '1' ? 1 : 0), len);
    ft_putstr(str);
    return (len);
}



int main(void)
{
    float f = __FLT_MAX__;
    double d = 0.42;
    long double d2 = __LDBL_MAX__;

    
    // printf("\nft_printf_f:\n");
    // printf_lf(f, 10);
    printf("\nft_printf_fd:\n");
    printf_f(d, sizeof(double));
    // printf("\nft_printf_lfd:\n");
    // printf_lf(d2, 10);

    printf("\n\nprintf:\n");
    printf("%f\n", d);
    // printf("%zd\n", ft_strlen(""));

}