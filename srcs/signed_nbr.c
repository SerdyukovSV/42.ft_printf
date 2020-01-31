/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:38:52 by gartanis          #+#    #+#             */
/*   Updated: 2020/01/31 21:26:10 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_space_signed(t_param *pm, int *len, char sign, int zero)
{
	int width;

	width = pm->width - (*len + zero + (sign ? 1 : 0));
	(width < 0) ? width = 0 : 0;
	(width > 0 || sign) ? pm->t_flag.space = 0 : 0;
	(pm->t_flag.dot) ? pm->t_flag.zero = 0 : 0;
	*len += width + zero + (sign ? 1 : 0) + (pm->t_flag.space ? 1 : 0);
	if (!pm->t_flag.minus)
	{
		while (!pm->t_flag.zero && width-- > 0)
			ft_putchar(32);
		if (pm->t_flag.space || sign)
			ft_putchar(sign ? sign : pm->t_flag.space);
		while ((pm->t_flag.zero && width-- > 0) || zero-- > 0)
			ft_putchar(48);
	}
	else if (pm->t_flag.minus)
		while (width-- > 0)
			ft_putchar(32);
}

static char	*nbr_conversion(intmax_t nbr, int *len)
{
	int			i;
	intmax_t	k;
	char		*result;

	k = nbr;
	i = (nbr == 0) ? 1 : 0;
	while (k)
	{
		k /= 10;
		i += 1;
	}
	*len = i;
	result = ft_memalloc(i);
	(nbr < 0) ? nbr *= -1 : 0;
	result[i--] = '\0';
	while (nbr)
	{
		result[i] = (nbr % 10) + 48;
		nbr /= 10;
		i--;
	}
	(nbr == 0) ? result[i] = '0' : 0;
	return (result);
}

int			print_signed(intmax_t nbr, t_param *pm)
{
	int		len;
	int		zero;
	int		count;
	char	*str;

	str = nbr_conversion(nbr, &len);
	(nbr < 0) ? pm->t_flag.plus = '-' : 0;
	zero = (pm->precision > len ? pm->precision - len : 0);
	if (!pm->t_flag.minus)
		print_space_signed(pm, &len, pm->t_flag.plus, zero);
	count = 0;
	if (pm->t_flag.minus)
		ft_putchar(pm->t_flag.plus ? pm->t_flag.plus : pm->t_flag.space);
	while (pm->t_flag.minus && count++ < zero)
		ft_putchar(48);
	ft_putstr(str);
	if (pm->t_flag.minus)
		print_space_signed(pm, &len, pm->t_flag.plus, zero);
	free(str);
	return (len);
}
