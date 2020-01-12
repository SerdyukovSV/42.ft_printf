#include "ft_printf.h"

static char *nbr_conversion(intmax_t nbr, int *len, int *sign, t_param *param)
{
    int i;
    intmax_t k;
    char *result;

    k = nbr;
    i = 0;
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

int  print_signed(intmax_t nbr, t_param *param)
{
    int len;
    int sign;
    int len_sp;
    char csign;
    char *str;

    str = nbr_conversion(nbr, &len, &sign, param);
    csign = verif_sign(param, nbr);
    len_sp = param->width - len - sign;
    if ((param->width && !param->t_flag.minus) && (param->t_flag.dot || param->t_flag.plus \
        || param->t_flag.space || param->width))
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
    free(str);
    return (len);
}