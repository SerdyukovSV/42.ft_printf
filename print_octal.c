/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:51:39 by gartanis          #+#    #+#             */
/*   Updated: 2020/01/30 00:54:59 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_space_octal(t_param *pm, int *len, int zero)
{
	int width;

	width = pm->width - (*len + zero);
	width = (width < 0) ? 0 : width;
	*len += width + zero;
	if (!pm->t_flag.minus)
	{
		while (!pm->t_flag.zero && width-- > 0)
			ft_putchar(32);
		while (pm->t_flag.zero && width-- > 0)
			ft_putchar(48);
		while (zero-- > 0)
			ft_putchar(48);
	}
	else if (pm->t_flag.minus)
		while (width-- > 0)
			ft_putchar(32);
}

static int	print_o(uintmax_t hex, t_param *pm)
{
	int		len;
	char	*str;
	int		zero;
	int		hash;

	hash = pm->t_flag.hash == '#' ? 1 : 0;
	len = get_hex_octal(hex, &str, pm->specifier);
	zero = hash + (pm->precision > len ? pm->precision - len - hash : 0);
	if (!pm->t_flag.minus)
		print_space_octal(pm, &len, zero);
	hash = 0;
	while (pm->t_flag.minus && hash++ < zero)
		ft_putchar(48);
	ft_putstr(str);
	if (pm->t_flag.minus)
		print_space_octal(pm, &len, zero);
	free(str);
	return (len);
}

int			print_octal(t_param *param, va_list args)
{
	int len;

	len = 0;
	if (param->modifier & H)
		len = print_o((unsigned short)va_arg(args, unsigned int), param);
	else if (param->modifier & HH)
		len = print_o((unsigned char)va_arg(args, unsigned int), param);
	else if (param->modifier & L)
		len = print_o(va_arg(args, unsigned long), param);
	else if (param->modifier & LL)
		len = print_o(va_arg(args, unsigned long long), param);
	else
		len = print_o(va_arg(args, unsigned int), param);
	return (len);
}
