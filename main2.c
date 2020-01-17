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
    if (!(bin_str = (unsigned char *)malloc(sizeof(unsigned char) * 52 + 1)))
        return (NULL);
    i = 0;
    while (res && i <= 52)
    {
        res *= 10;
        bin_str[i] = (unsigned char)res;
        res -= (long double)bin_str[i];
        bin_str[i] += 48;
        i += 1;        
    }
    bin_str[i] = '\0';
    return (bin_str);
}

// char    *addition_bigint(char *num1, char *num2)
// {
// }

int main(void)
{
    int nbr = 2;
    int n = -5;
    int n2 = 5;
    double d = 1.42;
    int i;

    char *str_bin;
    unsigned char str[sizeof(double) + 1];
    if (!(str_bin = (char *)malloc(sizeof(char) * 100)))
        return (0);
    ft_memcpy(str, &d, sizeof(double));
    i = sizeof(double);
    while (--i >= 0)
        str_bin = ft_strcat(str_bin, get_bin(str[i]));
    // printf("%s\n", str_bin);
    char sign = *str_bin == 1 ? '-' : '+';
    // printf("%c\n", sign);
    str_bin += 1;
    int exp = get_exponent(&str_bin);
    // printf("exp = %d\n", exp);
    unsigned char *convers_bin;
    convers_bin = get_mantisa(&str_bin);
    // ft_putstr((const char *)convers_bin);
    


    // printf("rais to power : %d\n", (int)power(nbr, n));
    // printf("rais to power : %f\n", power(nbr, n));
}