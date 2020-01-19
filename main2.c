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

long double  power(long double nbr, int n)
{
    if (n == 0)
        return (1);
    if (n < 0)
        return (power(1.0/nbr, -n));
    return (nbr * power(nbr, n - 1));
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

int get_exponent(char **exp)
{
    int i;
    int res;

    i = 10;
    res = 0;
    while (i >= 0)
    {
        res += (**exp - 48) * (power(2, i));
        *exp += 1;
        i -= 1;
    }
    return (res - 1023);
}

unsigned char    *get_mantisa(char **mant)
{
    int i;
    long double res;
    unsigned char *bin_str;

    i = -1;
    while (i >= (-52))
    {
        res += (**mant - 48) * (power(2, i));
        *mant += 1;
        i -= 1;
    }
    if (!(bin_str = (unsigned char *)malloc(sizeof(unsigned char) * 54 + 1)))
        return (NULL);
    i = 2;
    while (res && i <= 54)
    {
        res *= 10;
        bin_str[i] = (unsigned char)res;
        res -= (long double)bin_str[i];
        bin_str[i] += 48;
        i += 1;        
    }
    bin_str[0] = '1';
    bin_str[1] = '.';
    bin_str[i] = '\0';
    return (bin_str);
}

int *multiply_bigint(int *mant, int exp, int len)
{
    // unsigned char   *res_str;
    int             prod;
    int             *tmp;
    int             i;
    int             k;

    i = 0;
    k = 0;
    printf("\n");
    while (((mant[i] >= 0 && mant[i] <= 9) || mant[i] == 46) && i < len)
    {
        printf("%d ", mant[i]);
        i++;
    }
    if (mant[i] > 9 && i < len)
    {
        prod = mant[i] / 10;
        mant[i] = mant[i] % 10;
        if (mant[i - 1])
            mant[i - 1] += prod;
        else
        {
            if (!(tmp = ft_memalloc(ft_nbarrlen(mant) + 1)))
                return (0);
            tmp[k++] = prod;
            while (mant[i])
                tmp[k++] = mant[i++];
        }
        multiply_bigint(tmp, exp, ft_nbarrlen(mant) + 1);
    }
    i = 0;
    if (exp > 0)
    {
        while (((mant[i] >= 0 && mant[i] <= 9) || mant[i] == 46) && i < len)
        {
            /* if (mant[i] == 46)
                i++;
            mant[i] *= 2; */
            i++;
            // printf("%d ", mant[i]);
        }
        exp -= 1;
        multiply_bigint(mant, exp, ft_nbarrlen(mant) + 1);
    }
    return (0);
}

// } 1.397304687 499 9999200639422269887290894985198974609375
//   1.1159375
//  71.419999744 70368744177664

//1.1159375000000000266453525910037569701671600341796875
//1.1159375000000000266453525910037569701671600341796875 1 46 1 1 5 9 3 7 5

// (-1)Sign × (1 + Mantissa) × 2(Exponent adjusted);

int main(void)
{
    double d = 71.42;
    int     i;
    int     *tmp;
    char    *str_bin;

    unsigned char str[sizeof(double) + 1];
    if (!(str_bin = (char *)malloc(sizeof(char) * 100)))
        return (0);
    ft_memcpy(str, &d, sizeof(double));
    i = sizeof(double);
    while (--i >= 0)
        str_bin = ft_strcat(str_bin, get_bin(str[i]));
    char sign = *str_bin == 1 ? '-' : '+';
    str_bin += 1;
    int exp = get_exponent(&str_bin);
    unsigned char *cnvrs_bin = get_mantisa(&str_bin);
    printf("exp = %d : %d\n", exp, (int)power(2, exp));
    ft_putstr((const char *)cnvrs_bin);
    printf("\n");
    if(!(tmp = (int *)malloc(sizeof(int) * ft_strlen((const char *)cnvrs_bin))))
        return (0);
    i = -1;
    while (cnvrs_bin[++i])
    {
        tmp[i] = (cnvrs_bin[i] != 46) ? (cnvrs_bin[i] - 48) : 46;
        // printf("%d ", tmp[i]);
    }
    printf("\n");
    multiply_bigint(tmp, exp, i);


    // printf("\n%f\n", d);
}