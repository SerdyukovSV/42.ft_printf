/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:16:44 by gartanis          #+#    #+#             */
/*   Updated: 2019/12/27 20:34:47 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_space(int offset)
{
	int i;

	i = 0;
	while (i++ < offset)
		ft_putchar(' ');
}

int			print_percent(const char *pf)
{
	if (*pf == PERCENT)
		ft_putchar(PERCENT);
	return ((*pf == PERCENT) ? 0 : PRINT_ERROR);
}

static char	check_specifier(char *dspecif, const char *pf, t_param *param)
{
	int i;
	char *pdsp;
	char *flags;

	i = 0;
	while (pf[i])
	{
		pdsp = dspecif;
		flags = "+- #0.";
		if (*pf == PERCENT)
			return (0);
		if (ft_strchr(flags, pf[i]))
			i++;
		else if (ft_strchr(pdsp, pf[i]))
			return (pf[i]);
	}
	return (0);
}

int			pars_specifier(const char *pf, t_param *param)
{
	int ret;
	char *dspecif;

	ret = PRINT_ERROR;
	if (!(dspecif = (char *)malloc(sizeof(char)* (ft_strlen(SPECIFIER) + 1))))
		return (PRINT_ERROR);
	dspecif = ft_strcpy(dspecif, SPECIFIER);
	if ((param->specifier = check_specifier(dspecif, pf, param)))
	{
		if (!(ft_strchr(dspecif, *pf)))
			return (1);
		ret = get_param(pf, param);
	}
	free(dspecif);
	return (ret);
}