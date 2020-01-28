#include "ft_printf.h"

static void print_float(char *str, int precis, int *len)
{
    // printf("print_float\n");
    int k;
    char str_out[ft_strlen(str)];

    *len = -1;
    while (str[++(*len)] != '.')
        str_out[*len] = str[*len];
    str_out[*len] = (precis > 0) ? str[*len] : '\0';
    *len += 1;
    while (precis > 0 && str[*len])
    {
        if (precis == 1)
        {
            str_out[*len] = (str[*len+1] > '4') ? str[*len] + 1 : str[*len];
            k = *len;
            while (str_out[k] > '9')
            {
                str_out[k] = '0';
                str_out[k-1] += 1;
                k--;
            }
        }
        else
            str_out[*len] = str[*len];
        precis--;
        *len += 1;
    }
    str_out[*len] = '\0';
    ft_putstr(str_out);
    while (precis-- > 0)
    {
        ft_putchar('0');
        *len += 1;
    }
}

static char    *printf_f(double args, int len, t_param *param)
{
    int     exp;
    int     *bin_dec;
    int     *tmp;
    char    *str_out;
    char    *str;
    unsigned char str_mem[len + 1];

    if (!(str = (char *)malloc(sizeof(char) * 100)))
        return (0);
    ft_memcpy(str_mem, &args, len);
    while (--len >= 0)
        str = ft_strcat(str, get_bin(str_mem[len]));
    (*str == '1') ? param->t_flag.plus = '-' : 0;
    exp = get_exponent(str + 1, 10, 1023);
    bin_dec = get_mantisa(str + 12, &len, bin_dec);
    (exp >= 0) ? tmp = multiply_bigint(bin_dec, exp, &len) : 0;
    (exp <  0) ? tmp = divide_bigint(bin_dec, exp, &len) : 0;
    str_out = ft_dectostr(tmp, 0, len);
    return (str_out);
}

static char    *printf_lf(long double args, int len, t_param *param)
{
    int     exp;
    int     *bin_dec;
    int     *tmp;
    char    *str_out;
    char    *str;
    unsigned char str_mem[len + 1];

    if (!(str = (char *)malloc(sizeof(char) * 100)))
        return (0);
    ft_memcpy(str_mem, &args, len);
    while (--len >= 0)
        str = ft_strcat(str, get_bin(str_mem[len]));
    (*str == '1') ? param->t_flag.plus = '-' : 0;
    exp = get_exponent(str + 1, 14, 16383);
    bin_dec = get_mantisa(str + 17, &len, bin_dec);
    (exp >= 0) ? tmp = multiply_bigint(bin_dec, exp, &len) : 0;
    (exp <  0) ? tmp = divide_bigint(bin_dec, exp, &len) : 0;
    str_out = ft_dectostr(tmp, 0, len);
    return (str_out);
}

void    print_space_2(t_param *pm, int *len, char sign)
{
    // printf("print_space_2\n");
    int i;

    i = pm->width - *len - ((sign != 0) ? 1 : 0);
    *len += i;
    if (!pm->t_flag.minus)
    {
        while (!pm->t_flag.zero && i-- > 0)
            ft_putchar(32);
        if (pm->t_flag.space || sign)
            ft_putchar(sign != 0 ? sign : (!pm->width) ? 32 : 0);
        while (pm->t_flag.zero && i-- > 0)
            ft_putchar(48);
    }
    else if (pm->t_flag.minus)
    {
        while (i-- > 0)
            ft_putchar(32);
        if (pm->t_flag.space || sign)
            ft_putchar(sign != 0 ? sign : 32);
    }
}

int printf_float(va_list args, t_param *pm)
{
    int len;
    int i;
    char *str;
    char *space_zero;

    (pm->t_flag.dot != DOT) ? pm->precision = 6 : 0;
    if (pm->modifier & UPP_L)
        str = printf_lf(va_arg(args, long double), 10, pm);
    else
        str = printf_f(va_arg(args, double), 8, pm);
    len = ft_strlen(str);
    len = (pm->precision > len) ? pm->precision - len : len;
    if (!pm->t_flag.minus)
        print_space_2(pm, &len, pm->t_flag.plus);
    print_float(str, pm->precision, &i);
    if (pm->t_flag.minus)
        print_space_2(pm, &len, pm->t_flag.plus);
    return (len);
}