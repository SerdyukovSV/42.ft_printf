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

int get_exponent(char **exp, int len, int correct)
{
    int res;

    res = 0;
    while (len >= 0)
    {
        res += (**exp - 48) * (ft_power(2, len));
        *exp += 1;
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
    *len -= 1;
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

int *get_mantisa(char **mant, int *len, int *bin_dec)
{
    int i;
    int k;
    int tmp;
    long double res[64];

    i = -1;
    k = 0;
    while (**mant != '\0' && i >= -64)
    {
        res[k++] = (**mant - 48) * (ft_power(2, i--));
        *mant += 1;
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

/*
0.000335999999999999981407233784480581562092993408441543579101562

*/
// (-1)Sign × (1 + Mantissa) × 2(Exponent adjusted);

int printf_f(double d)
{
    int     i;
    int     len;
    int     *bin_dec;
    char    *str_bin;

    unsigned char str[sizeof(double) + 1];
    if (!(str_bin = (char *)malloc(sizeof(char) * 100)))
        return (0);
    ft_memcpy(str, &d, sizeof(double));
    len = sizeof(double);
    while (--len >= 0)
        str_bin = ft_strcat(str_bin, get_bin(str[len]));
    char sign = *str_bin == 1 ? '-' : '+';
    str_bin += 1;
    int exp = get_exponent(&str_bin, 10, 1023);
    bin_dec = get_mantisa(&str_bin, &len, bin_dec);

    printf("exp = %d\n", exp);

    bin_dec = multiply_bigint(bin_dec, exp, &len);

    i = -1;

    while (i++ < len)
    {
        if (bin_dec[i] == 46)
            printf(".");
        else
            printf("%d", bin_dec[i]);
    }
    return (len);
}

int printf_lf(long double d)
{
    int     i;
    int     len;
    int     *bin_dec;
    char    *str_bin;

    unsigned char str[10 + 1];
    if (!(str_bin = (char *)malloc(sizeof(char) * 100)))
        return (0);
    ft_memcpy(str, &d, 10);
    len = 10;
    while (--len >= 0)
        str_bin = ft_strcat(str_bin, get_bin(str[len]));
    char sign = *str_bin == 1 ? '-' : '+';
    str_bin += 1;
    int exp = get_exponent(&str_bin, 14, 16383);
    str_bin += 1;
    bin_dec = get_mantisa(&str_bin, &len, bin_dec);
    if (exp >= 0)
        bin_dec = multiply_bigint(bin_dec, exp, &len);
    else
        bin_dec = divide_bigint(bin_dec, exp, &len);
    i = -1;
    while (i++ < len)
    {
        if (bin_dec[i] == 46)
            printf(".");
        else
            printf("%d", bin_dec[i]);
    }
    return (len);
}
//0.0000038096785887069446741026723657341790385544300079345703125
//0.667999999999892679625190794467926025390625
int main(void)
{
    double d = 0.42;
    long double d2 = 0.0000000000000000000000000000000000000000000042;
    float f = __FLT_MAX__;

    int i = sizeof(float);
    // printf("float = %lu\ndouble = %lu\nlong double = %lu\n", sizeof(float), sizeof(double), sizeof(long double));

    // printf("\nft_printf_f:\n");
    // printf_f(f);
    printf("\nft_printf_lf:\n");
    printf_lf(d2);

    printf("\n\nprintf:\n");
    printf("%.264Lf\n", d2);
    printf("%zd\n", ft_strlen(""));

}