#include "ft_printf.h"

static void    print_flags(char ch1, int n1, char ch2, int n2, char ch3, int n3)
{
    int i;

    i = 0;
    while (ch1 && i++ < n1)
        ft_putchar(ch1);
    i = 0;
    while (ch2 && i++ < n2)
        ft_putchar(ch2);
    i = 0;
    while (ch3 && i++ < n3)
        ft_putchar(ch3);
}

static char *nbr_conversion(intmax_t nbr, int *len, int *sign, char *csign, t_param *param)
{
    int i;
    intmax_t k;
    char *result;

    k = nbr;
    i = 0;
    *csign = (param->t_flag.plus && nbr > 0) ? '+' : ((nbr < 0) ? '-' \
        : param->t_flag.space && param->width && param->t_flag.zero && \
        !param->t_flag.dot ? ' ' : param->t_flag.space && !param->width ? \
        ' ' : param->t_flag.space && param->t_flag.minus ? ' ' : 0);
    *sign = (param->t_flag.plus && nbr > 0) ? 1 : (nbr < 0) ? 1 : \
        param->t_flag.space && param->t_flag.minus ? 1 : 0;
    while (k)
    {
        k /= 10;
        i += 1;
    }
    *len = i;
    result = ft_memalloc(i);
    (nbr < 0) ? nbr *= -1 : 0;
    result[i--] = '\0';
    while (nbr)
    {
        result[i] = (nbr % 10) + 48;
        nbr /= 10;
        i--;
    }
    return (result);
}

static int  print_signed(intmax_t nbr, t_param *param)
{
    int len;
    int sign;
    int len_sp;
    char csign;
    char *str;

    str = nbr_conversion(nbr, &len, &sign, &csign, param);
    len_sp = param->width - len - sign;
    if ((param->width && !param->t_flag.minus) && (param->t_flag.dot || param->t_flag.plus \
        || param->t_flag.space))
    {
        if (param->t_flag.zero && !param->t_flag.dot)
            print_flags(csign, 1, '0', len_sp - (csign == ' ' ? 1 : 0), 0, 0);
        else if (param->t_flag.dot)
            print_flags(' ', len_sp - (param->precision - len), csign, 1, '0', param->precision - len);
        else
            print_flags(' ', len_sp - (csign == ' ' ? 1 : 0), csign, 1, 0, 0);
    }
    else if (param->t_flag.dot || param->t_flag.plus || param->t_flag.space)
        print_flags(csign, 1, '0', param->precision - len, 0, 0);
    else if (nbr < 0)
        ft_putchar('-');
    ft_putstr(str);
    if (param->width && param->t_flag.minus)
        print_flags(' ', len_sp - (((param->precision - len) < 0) ? \
            0 : param->precision - len), 0, 0, 0, 0);
    return (len);
}

static int  unsigned_nbr(t_param *param, va_list args)
{
    int len;

    if (param->modifier & H)
        len = print_signed((unsigned short)va_arg(args, unsigned int), param);
    else if (param->modifier & HH)
        len = print_signed((unsigned char)va_arg(args, unsigned int), param);
    else if ((param->modifier & L) || (param->specifier == 'U'))
        len = print_signed(va_arg(args, unsigned long), param);
    else if (param->modifier & LL)
        len = print_signed(va_arg(args, unsigned long long), param);
    else
        len = print_signed(va_arg(args, unsigned int), param);
    return (len);
}

static int  signed_nbr(t_param *param, va_list args)
{
    int len;

    len = 0;
    if (param->modifier & H)
        len = print_signed((short)va_arg(args, int), param);
    else if (param->modifier & HH)
        len = print_signed((char)va_arg(args, int), param);
    else if ((param->modifier & L) || (param->specifier == 'D'))
        len = print_signed(va_arg(args, long), param);
    else if (param->modifier & LL)
        len = print_signed(va_arg(args, long long), param);
    else
        len = print_signed(va_arg(args, int), param);
    return (len);
}

int print_decimal(t_param *param, va_list args)
{
    int len;

    len = 0;
    if (param->specifier == 'd' || param->specifier == 'D' || param->specifier == 'i')
        len = signed_nbr(param, args);
    else if (param->specifier == 'u' || param->specifier == 'U')
        len = unsigned_nbr(param, args);
    else if (param->specifier == 'f')
        ;
    return (len);    
}