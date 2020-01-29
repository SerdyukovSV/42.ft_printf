#include "ft_printf.h"

void    print_flags(char ch1, int n1, char ch2, int n2, char ch3, int n3)
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

char    verif_sign(t_param *param, intmax_t nbr)
{
    char sign;

    if (param->specifier == 'u' || param->specifier == 'U')
    {
        sign = 0;
    }
    else
    {
        sign = (param->t_flag.plus && nbr > 0) ? '+' : ((nbr < 0) ? '-' \
        : param->t_flag.space && param->width && param->t_flag.zero && \
        !param->t_flag.dot ? ' ' : param->t_flag.space && !param->width ? \
        ' ' : param->t_flag.space && param->t_flag.minus ? ' ' : 0);
    }
    return (sign);
}

static int  unsigned_nbr(t_param *param, va_list args)
{
    int len;

    if (param->modifier & H)
        len = print_unsigned((unsigned short)va_arg(args, unsigned int), param);
    else if (param->modifier & HH)
        len = print_unsigned((unsigned char)va_arg(args, unsigned int), param);
    else if ((param->modifier & L) || (param->specifier == 'U'))
        len = print_unsigned(va_arg(args, unsigned long), param);
    else if (param->modifier & LL)
        len = print_unsigned(va_arg(args, unsigned long long), param);
    else
        len = print_unsigned(va_arg(args, unsigned int), param);
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
    if (param->specifier == 'd' || param->specifier == 'i')
        len = signed_nbr(param, args);
    else if (param->specifier == 'u')
        len = unsigned_nbr(param, args);
    return (len);    
}