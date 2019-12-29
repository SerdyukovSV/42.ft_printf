/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:22:15 by gartanis          #+#    #+#             */
/*   Updated: 2019/12/29 18:42:49 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_flag(char flag, t_param *param)
{
	(flag == PLUS) ? (param->t_flag.plus = PLUS) : 0;
	(flag == MINUS) ? (param->t_flag.minus = MINUS) : 0;
	(flag == SPACE) ? (param->t_flag.space = SPACE) : 0;
	(flag == ZERO) ? (param->t_flag.zero = ZERO) : 0;
	(flag == HASH) ? (param->t_flag.hash = HASH) : 0;
	return(flag == PLUS || flag == MINUS || flag == SPACE \
		|| flag == ZERO || flag == HASH);
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

	ret = 0;
	nbr = *precis;
	if (*nbr++ == DOT)
		if ((param->precision = ft_atoi(nbr)))
			while (ft_isdigit(nbr[ret]))
				ret += 1;
	return (ret);
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
	return (ret);
}