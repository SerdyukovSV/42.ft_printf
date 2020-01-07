/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:22:15 by gartanis          #+#    #+#             */
/*   Updated: 2020/01/07 20:16:53 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_flag(char flag, t_param *param)
{
	(flag == '+') ? (param->t_flag.plus = '+') : 0;
	(flag == '-') ? (param->t_flag.minus = '-') : 0;
	(flag == ' ') ? (param->t_flag.space = ' ') : 0;
	(flag == '0') ? (param->t_flag.zero = '0') : 0;
	(flag == '#') ? (param->t_flag.hash = '#') : 0;
	return(flag == '+' || flag == '-' || flag == ' ' \
		|| flag == '0' || flag == '#');
}

static int	get_width(const char **width, t_param *param)
{
	// printf("get_width\n"); //////////////////////////////////////////
	int ret;
	const char *nbr;

	ret = 0;
	nbr = *width;
	if ((param->width = ft_atoi(nbr)) > 0)
		while (ft_isdigit(nbr[ret]))
			ret += 1;
	// printf("param->width = %d\n", param->width); //////////////////////////////////////////
	return (ret);
}

static int	get_precision(const char **precis, t_param *param)
{
	// printf("get_precision\n"); //////////////////////////////////////////
	int ret;
	const char *nbr;
	int count;

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
	int i;

	i = 0;
	if (*modif[i] == 'h')
	{
		param->modifier |= (*modif[i + 1] == 'h') ? HH : H;
		i = (param->modifier & HH) ? 2 : 1;
	}
	else if (*modif[i] == 'l')
	{
		param->modifier |= (*modif[i + 1] == 'l') ? LL : L;
		i = (param->modifier & LL) ? 2 : 1;
	}
	else if (*modif[i] == 'L')
	{
		param->modifier |= UPP_L;
		i += 1;
	}
	return (i);
}

int	get_param(const char **pf, t_param *param)
{
	// printf("get_param\n"); //////////////////////////////////////////
	int ret;

    ret = 0;
	while (get_flag(**pf, param))
		*pf += 1;
	if ((ret = get_width(pf, param)))
		*pf += ret;
	if ((ret = get_precision(pf, param)))
		*pf += ret;
	if ((ret = get_modifier(pf, param)))
		*pf += ret;
	if (param->specifier)
		*pf += 1;
	return (ret);
}