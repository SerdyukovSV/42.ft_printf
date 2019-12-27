/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:16:44 by gartanis          #+#    #+#             */
/*   Updated: 2019/12/27 19:38:26 by gartanis         ###   ########.fr       */
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

int			print_no_specifier(const char *pf)
{
	if (*pf == PERCENT)
		ft_putchar(PERCENT);
	return ((*pf == PERCENT) ? 0 : PRINT_ERROR);
}

static char	check_specifier(char *dspecif, const char *pf, t_param *param)
{
	write(1, "EROR_2\n", 7);
	int i;
	char *pdsp;
	// char *ch;

	i = 0;
	while (pf[i])
	{
		pdsp = dspecif;
		// ch = ft_strchr(pdsp, pf[i]);
		if (ft_strchr(pdsp, pf[i]) /* pf[i] == *ch */)
			return (pf[i]);
		i++;
	}
	return (0);
}

int			pars_specifier(const char *pf, t_param *param)
{
	write(1, "\nEROR_1\n", 8);
	int ret;
	char *dspecif;

	ret = PRINT_ERROR;
	if (!(dspecif = (char *)malloc(sizeof(char)* (ft_strlen(SPECIFIER) + 1))))
		return (PRINT_ERROR);
	dspecif = ft_strcpy(dspecif, SPECIFIER);
	if ((param->specifier = check_specifier(dspecif, pf, param)))
	{
		write(1, "1\n", 2);
		if (!(ft_strchr(dspecif, *pf)))
			return (1);
		ret = get_param(pf, param);
	}
	return (ret);
}