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

double  power(double nbr, long n)
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

int main(void)
{
    int nbr = 2;
    int n = -5;
    int n2 = 5;
    double d = 1.41999999999999992894572642399E0;
    int i;

    char *str_bin;
    unsigned char str[sizeof(double) + 1];
    if (!(str_bin = (char *)malloc(sizeof(char) * 100)))
        return (0);
    ft_memcpy(str, &d, sizeof(double));
    i = sizeof(double);
    while (--i >= 0)
    {
            str_bin = ft_strcat(str_bin, get_bin(str[i]));
            printf("%s\n", str_bin);
    }


    // printf("rais to power : %d\n", (int)power(nbr, n));
    // printf("rais to power : %f\n", power(nbr, n));
}