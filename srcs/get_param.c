/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:22:15 by gartanis          #+#    #+#             */
/*   Updated: 2020/01/31 17:29:04 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_flag(char flag, t_param *param)
{
	(flag == '+') ? (param->t_flag.plus = '+') : 0;
	(flag == '-') ? (param->t_flag.minus = '-') : 0;
	(flag == ' ') ? (param->t_flag.space = ' ') : 0;
	(flag == '0') ? (param->t_flag.zero = '0') : 0;
	(flag == '#') ? (param->t_flag.hash = '#') : 0;
	return (flag == '+' || flag == '-' || flag == ' ' \
		|| flag == '0' || flag == '#');
}

static int	get_width(const char **width, t_param *param)
{
	int			ret;
	const char	*nbr;

	ret = 0;
	nbr = *width;
	if ((param->width = ft_atoi(nbr)) > 0)
		while (ft_isdigit(nbr[ret]))
			ret += 1;
	return (ret);
}

static int	get_precision(const char **precis, t_param *param)
{
	int			ret;
	const char	*nbr;
	int			count;

	ret = 0;
	count = 0;
	nbr = *precis;
	if (*nbr++ == DOT)
	{
		ret += 1;
		while (ft_isdigit(nbr[count]))
			count++;
		ret += count;
		param->t_flag.dot = DOT;
		param->precision = ft_atoi(nbr);
	}
	return (ret);
}

static int	get_modifier(const char **modif, t_param *param)
{
	int			i;
	const char	*ptr;

	i = 0;
	ptr = *modif;
	if (ptr[i] == 'h')
	{
		param->modifier |= (ptr[i + 1] == 'h') ? HH : H;
		i = (param->modifier & HH) ? 2 : 1;
	}
	else if (ptr[i] == 'l')
	{
		param->modifier |= (ptr[i + 1] == 'l') ? LL : L;
		i = (param->modifier & LL) ? 2 : 1;
	}
	else if (ptr[i] == 'L')
	{
		param->modifier |= UPP_L;
		i += 1;
	}
	return (i);
}

int			get_param(const char **pf, t_param *param)
{
	int ret;
	int len;

	ret = 0;
	len = 0;
	while (get_flag(**pf, param) ? (*pf += 1) : 0)
		len++;
	if ((ret = get_width(pf, param)) ? (*pf += ret) : 0)
		len++;
	if ((ret = get_precision(pf, param)) ? (*pf += ret) : 0)
		len++;
	if ((ret = get_modifier(pf, param)) ? (*pf += ret) : 0)
		len++;
	if (param->specifier ? (*pf += 1) : 0)
		len++;
	return (len);
}
