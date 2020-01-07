/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:16:44 by gartanis          #+#    #+#             */
/*   Updated: 2020/01/07 16:12:36 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_space(int width)
{
	int i;

	i = 0;
	while (i++ < width)
		ft_putchar(SPACE);
}

int			print_percent(const char **pf)
{
	if (**pf == PERCENT)
	{
		ft_putchar(PERCENT);
		*pf += 1;
	}
	else
		return (PRINT_ERROR);
	return (1);
}

static int	check_specifier(char *dspecif, const char **pf, t_param *param)
{
	// printf("check_specifier\n"); //////////////////////////////////////////
	int i;
	char *pdsp;
	char *flags;
	const char *cp;

	i = 0;
	cp = *pf;
	while (*cp)
	{
		pdsp = dspecif;
		flags = "+- #0";
		if (*cp == PERCENT)
			return (0);
		while (ft_strchr(flags, *cp))
			cp += 1;
		while (ft_isdigit(*cp) || *cp == DOT)
			cp += 1;
		if (ft_strchr(pdsp, *cp))
			break ;
		else
			return (0);
	}
	param->specifier = *cp;
	return (1);
}

int			pars_specifier(const char **pf, t_param *param)
{
	// printf("\npars_specifier\n"); //////////////////////////////////////////
	int ret;
	char *dspecif;

	ret = PRINT_ERROR;

	dspecif = ft_strdup(SPECIFIER);
	if ((check_specifier(dspecif, pf, param)))
	{
		if (ft_strchr(dspecif, **pf))
		{
			*pf += 1;
			return (1);
		}
		ret = get_param(pf, param);
	}
	free(dspecif);
	return (ret);
}