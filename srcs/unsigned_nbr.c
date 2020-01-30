/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:18:34 by gartanis          #+#    #+#             */
/*   Updated: 2020/01/31 01:24:10 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_space_unsign(t_param *pm, int *len, int zero)
{
	int width;

	width = pm->width - (*len + zero);
	(width < 0) ? width = 0 : 0;
	(pm->t_flag.dot) ? pm->t_flag.zero = 0 : 0;
	*len += width + zero;
	if (!pm->t_flag.minus)
	{
		while (!pm->t_flag.zero && width-- > 0)
			ft_putchar(32);
		while ((pm->t_flag.zero && width-- > 0) || zero-- > 0)
			ft_putchar(48);
	}
	else if (pm->t_flag.minus)
		while (width-- > 0)
			ft_putchar(32);
}

static char	*unbr_conversion(uintmax_t nbr, int *len)
{
	int			i;
	uintmax_t	k;
	char		*result;

	k = nbr;
	i = 0;
	while (k)
	{
		k /= 10;
		i += 1;
	}
	*len = i;
	result = ft_memalloc(i);
	result[i--] = '\0';
	while (nbr)
	{
		result[i] = (nbr % 10) + 48;
		nbr /= 10;
		i--;
	}
	return (result);
}

int			print_unsigned(uintmax_t nbr, t_param *pm)
{
	int		len;
	int		count;
	int		zero;
	char	*str;

	str = unbr_conversion(nbr, &len);
	zero = pm->precision > len ? pm->precision - len : 0;
	if (!pm->t_flag.minus)
		print_space_unsign(pm, &len, zero);
	count = 0;
	while (pm->t_flag.minus && count++ < zero)
		ft_putchar(48);
	ft_putstr(str);
	if (pm->t_flag.minus)
		print_space_unsign(pm, &len, zero);
	free(str);
	return (len);
}
