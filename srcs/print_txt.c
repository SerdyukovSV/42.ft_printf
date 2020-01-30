/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_txt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 20:47:18 by gartanis          #+#    #+#             */
/*   Updated: 2020/01/31 01:18:33 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_string(t_param *param, va_list args)
{
	char	*src;
	char	*dst;
	int		len;

	src = va_arg(args, char *);
	if (param->precision != 0)
	{
		if (!(dst = (char *)malloc(sizeof(char) * (param->precision + 1))))
			return (0);
		if ((dst = ft_strncpy(dst, src, param->precision)))
			src = dst;
	}
	len = param->precision == 0 ? 0 : ft_strlen(src);
	if (param->width && (param->t_flag.minus != MINUS))
		print_space(param->width - len, SPACE);
	if (!(param->precision == 0 && param->t_flag.dot == DOT))
		ft_putstr(src);
	if (param->precision != 0)
		free(dst);
	if (param->width && (param->t_flag.minus == MINUS))
		print_space(param->width - len, SPACE);
	len += param->width > len ? param->width - len : 0;
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
