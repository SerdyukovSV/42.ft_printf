/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:22:15 by gartanis          #+#    #+#             */
/*   Updated: 2019/12/27 19:28:28 by gartanis         ###   ########.fr       */
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

static int	get_width(const char *width, t_param *param)
{
	int ret;

	ret = 0;
	if ((param->width = ft_atoi(width)) > 0)
	{
		while (ft_isdigit(width[ret]))
			ret += 1;
	}
	return (ret);
}

static int	get_precision(const char *precis, t_param *param)
{
	int ret;

	ret = 0;
	if (*precis++ == DOT)
		if ((param->precision = ft_atoi(precis)))
			while (ft_isdigit(precis[ret]))
				ret += 1;
	return (ret);
}

int	get_param(const char *pf, t_param *param)
{
    write(1, "EROR_3\n", 7);
	int ret;

	while (get_flag(*pf, param))
		pf++;
	if ((ret = get_width(pf, param)))
		pf += ret;
	if ((ret = get_precision(pf, param)))
		pf += ret;
	
	return (ret);
}