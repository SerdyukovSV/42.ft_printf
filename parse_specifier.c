/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:16:44 by gartanis          #+#    #+#             */
/*   Updated: 2019/12/26 21:39:15 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space(int offset)
{
	int i;

	i = 0;
	while (i++ < offset)
		ft_putchar(' ');
}

static int	get_flag(char flag, t_param param)
{
	param.t_flag.plus = (flag == PLUS) ? PLUS : NULL;
	param.t_flag.minus = (flag == MINUS) ? MINUS : NULL;
	param.t_flag.space = (flag == SPACE) ? SPACE : NULL;
	param.t_flag.zero = (flag == ZERO) ? ZERO : NULL;
	param.t_flag.hash = (flag == HASH) ? HASH : NULL;
	return(flag == PLUS || flag == MINUS || flag == SPACE \
		|| flag == ZERO || flag == HASH);
}

int	get_param(char *pf, t_param *param)
{
	int ret;

	if (!(ret = get_flag(*pf, param)))
		return (ret);
	pf++;
	if (get_width())
	// if ((parameters.width = ft_atoi(specif)) > 0)
	// 	print_offset(parameters.width);
	
	return (print_printf(parameters.specifier, &parameters, args));
}

static char	check_specifier(char *dspecif, char *pf, t_param *param)
{
	int i;
	char *pdsp;

	i = 0;
	while (pf[i])
	{
		pdsp = dspecif;
		if (pf[i] == ft_strchr(pdsp, pf[i]))
			return (pf[i]);
		i++;
	}
	return (NULL);
}

int	pars_specifier(char *pf, t_param *param)
{
	int ret;
	char *dspecif;

	ret = PRINT_ERROR;
	if (!(dspecif = (char *)malloc(sizeof(char)* (ft_strlen(SPECIFIER) + 1))))
		return (PRINT_ERROR);
	dspecif = ft_strcpy(dspecif, SPECIFIER);
	if ((param->specifier = check_specifier(dspecif, pf, param)) && \
		!(ft_strchr(dspecif, *pf)))
		ret = get_param(pf, param);
	return (ret);
}