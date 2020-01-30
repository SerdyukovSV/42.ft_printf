/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_fl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:37:07 by gartanis          #+#    #+#             */
/*   Updated: 2020/01/31 00:29:55 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char				*get_bin(unsigned char c)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * 9)))
		return (0);
	while (c != 0)
	{
		tmp[i] = "01"[c % 2];
		c /= 2;
		i++;
	}
	while (i != 8)
		tmp[i++] = '0';
	tmp[i] = '\0';
	tmp = ft_strrev(tmp);
	return (tmp);
}

int					get_exponent(char *exp, int len, int correct)
{
	int res;

	res = 0;
	while (len >= 0)
	{
		res += (*exp - 48) * (ft_power(2, len));
		exp += 1;
		len -= 1;
	}
	return (res - correct);
}

static long double	*bintoflt_mant(char *mant, int *len)
{
	int			k;
	long double	*res;

	*len = -1;
	k = 0;
	if (!(res = (long double *)malloc(sizeof(long double) * 64)))
		return (0);
	while (*mant != '\0' && *len >= -64)
	{
		res[k] = (*mant - 48) * (ft_power(2, (*len)--));
		k++;
		mant += 1;
	}
	return (res);
}

int					*get_mantisa(char *mant, int *len, int *bin_dec)
{
	int			i;
	int			k;
	int			tmp;
	long double	*res;

	res = bintoflt_mant(mant, &i);
	if (!(bin_dec = (int *)malloc(sizeof(int) * (++i * -1) + 2)))
		return (0);
	bin_dec[0] = 1;
	bin_dec[1] = 46;
	*len = (i * -1) + 2;
	i = -1;
	while (++i < (*len - 2))
	{
		k = 2;
		while (res[i])
		{
			res[i] *= 10;
			tmp = (int)res[i];
			bin_dec[k++] += tmp;
			res[i] -= (long double)tmp;
		}
		bin_dec = sort_bigint(bin_dec, &k);
	}
	return (bin_dec);
}
