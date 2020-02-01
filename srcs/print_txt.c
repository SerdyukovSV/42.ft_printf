/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_txt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 20:47:18 by gartanis          #+#    #+#             */
/*   Updated: 2020/02/01 18:14:01 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_no_specifier(t_param *pm, const char **pf)
{
	int	len;

	if ((len = find_percent(pf)))
	{
		if (get_param(pf, pm))
		{
			if (!pm->t_flag.minus)
				print_space(pm->width - len, pm->t_flag.zero ? '0' : ' ');
			ft_putchar('%');
			if (pm->t_flag.minus)
				print_space(pm->width - len, ' ');
		}
		else
			ft_putchar('%');
		*pf += 1;
		len += pm->width > len ? pm->width - len : 0;
	}
	return (len);
}

int	print_string(t_param *pm, va_list args)
{
	char	*str;
	char	*dst;
	int		len;

	str = va_arg(args, char *);
	if (pm->precision != 0)
	{
		if (!(dst = (char *)malloc(sizeof(char) * (pm->precision + 1))))
			return (0);
		if ((dst = ft_strncpy(dst, str, pm->precision)))
			str = dst;
	}
	len = ft_strlen(!str ? "(null)" : str);
	(pm->t_flag.dot && pm->precision == 0) ? len = 0 : 0;
	if (pm->width && (pm->t_flag.minus != MINUS))
		print_space(pm->width - len, SPACE);
	if (!(pm->precision == 0 && pm->t_flag.dot == DOT))
		ft_putstr(!str ? "(null)" : str);
	if (pm->precision != 0)
		free(dst);
	if (pm->width && (pm->t_flag.minus == MINUS))
		print_space(pm->width - len, SPACE);
	len += pm->width > len ? pm->width - len : 0;
	return (len);
}

int	print_char(t_param *param, va_list args)
{
	char	ch;
	int		len;

	len = sizeof(char);
	ch = va_arg(args, int);
	if (param->width && (param->t_flag.minus != MINUS))
		print_space(param->width - len, SPACE);
	ft_putchar(ch);
	if (param->width && (param->t_flag.minus == MINUS))
		print_space(param->width - len, SPACE);
	len += param->width > len ? param->width - len : 0;
	return (len);
}
