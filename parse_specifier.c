/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:16:44 by gartanis          #+#    #+#             */
/*   Updated: 2019/12/29 18:31:41 by gartanis         ###   ########.fr       */
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
		ft_putchar(PERCENT);
	return ((**pf == PERCENT) ? 0 : PRINT_ERROR);
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
		while (ft_isdigit(*cp))
			// printf("isdigit %c\n", (*pf[i])); //////////
			cp += 1;
		if (ft_strchr(pdsp, *cp))
			break ;
			// printf("6\n"); //////////////////////////////////////////
		else
			return (0);
	}
	param->specifier = *cp;
	// printf("specif %c\n", *cp); //////////
	return (1);
}

int			pars_specifier(const char **pf, t_param *param)
{
	// printf("pars_specifier\n"); //////////////////////////////////////////
	int ret;
	char *dspecif;

	ret = PRINT_ERROR;
	if (!(dspecif = (char *)malloc(sizeof(char)* (ft_strlen(SPECIFIER) + 1))))
		return (PRINT_ERROR);
	dspecif = ft_strcpy(dspecif, SPECIFIER);
	if ((check_specifier(dspecif, pf, param)))
	{
		if (ft_strchr(dspecif, **pf))
			return (1);
		ret = get_param(pf, param);
	}
	free(dspecif);
	return (ret);
}