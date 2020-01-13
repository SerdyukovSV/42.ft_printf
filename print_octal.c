/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:51:39 by gartanis          #+#    #+#             */
/*   Updated: 2020/01/13 20:05:08 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unsigned_octal(uintmax_t hex, t_param *prm)
{
	int len;
	char *str;
	int hash;
	int len_sp;

	hash = prm->t_flag.hash == '#' ?	1 : 0;
	len = get_hexadecimal(hex, &str, prm);
	len_sp = prm->width - len - hash - \
		(prm->precision > 0 ? prm->precision - len : 0);
	if (!prm->t_flag.minus && (prm->width || prm->t_flag.dot))
    {
        if (prm->t_flag.zero && !prm->t_flag.dot)
			print_flags2("0", hash, "0", len_sp, 0, 0);
        else if (prm->t_flag.dot)
            print_flags2(" ", len_sp, "0", hash, "0", prm->precision - len);
        else
            print_flags2(" ", len_sp, "0", hash, 0, 0);
    }
	else if (hash > 0 || prm->t_flag.dot)
		print_flags2("0", hash, "0", prm->precision - len, 0, 0);
    ft_putstr(str);
    if (prm->t_flag.minus)
        print_flags2(0, 0, 0, 0, " ", len_sp);
    free(str);
	return(len);
}

int			print_octal(t_param *param, va_list args)
{
	int len;

	len = 0;
	if (param->modifier & H)
		len = unsigned_octal((unsigned short)va_arg(args, unsigned int), param);
	else if (param->modifier & HH)
		len = unsigned_octal((unsigned char)va_arg(args, unsigned int), param);
	else if (param->modifier & L)
		len = unsigned_octal(va_arg(args, unsigned long), param);
	else if (param->modifier & LL)
		len = unsigned_octal(va_arg(args, unsigned long long), param);
	else
		len = unsigned_octal(va_arg(args, unsigned int), param);
	return (len);
}