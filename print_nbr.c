#include "ft_printf.h"

int print_signed(intmax_t nbr, t_param *param)
{
}

int unsigned_nbr(t_param *param, va_list args)
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

int signed_nbr(t_param *param, va_list args)
{
    int len;

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
    if (param->specifier == 'd' || param->specifier == 'D' || param->specifier == 'i')
        signed_nbr(param, args);
    else if (param->specifier == 'u' || param->specifier == 'U')
        unsigned_nbr(param, args);
}