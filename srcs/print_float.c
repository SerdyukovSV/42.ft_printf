/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:03:05 by gartanis          #+#    #+#             */
/*   Updated: 2020/02/04 21:32:50 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*rounding_float(char *str, int precis)
{
	int		len;

	len = ft_strchrpos(str, 46) + 1;
	while (str[len])
	{
		if ((precis--) == 1 && str[len] != '.')
		{
			(str[len + 1] > '4') ? str[len] += 1 : 0;
			str[len + 1] = '\0';
			while (str[len] > '9')
			{
				str[len--] = '0';
				str[len] += 1;
			}
			break ;
		}
		len++;
	}
	return (str);
}

static char	*printf_f(double args, int len, t_param *param)
{
	int				exp;
	int				*bin_dec;
	char			*str;
	char			*tmp;
	unsigned char	str_mem[len];

	if (!(str = (char *)malloc(sizeof(char) * 100)))
		return (0);
	ft_memcpy(str_mem, &args, len);
	while (--len >= 0)
	{
		tmp = get_bin(str_mem[len]);
		str = ft_strcat(str, tmp);
		free(tmp);
	}
	(*str == '1') ? param->t_flag.plus = '-' : 0;
	exp = get_exponent(str + 1, 10, 1023);
	bin_dec = get_mantisa(str + 12, &len);
	free(str);
	(exp >= 0) ? bin_dec = multiply_bigint(bin_dec, exp, &len) : 0;
	(exp < 0) ? bin_dec = divide_bigint(bin_dec, exp, &len) : 0;
	str = ft_dectostr(bin_dec, 0, len);
	free(bin_dec);
	return (str);
}

static char	*printf_lf(long double args, int len, t_param *param)
{
	int				exp;
	int				*bin_dec;
	char			*str;
	char			*tmp;
	unsigned char	str_mem[len];

	if (!(str = (char *)malloc(sizeof(char) * 100)))
		return (0);
	ft_memcpy(str_mem, &args, len);
	while (--len >= 0)
	{
		tmp = get_bin(str_mem[len]);
		str = ft_strcat(str, tmp);
		free(tmp);
	}
	(*str == '1') ? param->t_flag.plus = '-' : 0;
	exp = get_exponent(str + 1, 14, 16383);
	bin_dec = get_mantisa(str + 17, &len);
	free(str);
	(exp >= 0) ? bin_dec = multiply_bigint(bin_dec, exp, &len) : 0;
	(exp < 0) ? bin_dec = divide_bigint(bin_dec, exp, &len) : 0;
	str = ft_dectostr(bin_dec, 0, len);
	free(bin_dec);
	return (str);
}

static void	print_space_float(t_param *pm, int *len, char sign, char space)
{
	int width;

	width = pm->width - (*len + (sign ? 1 : 0)) - \
		(pm->t_flag.zero && space ? 1 : 0);
	width = (width < 0) ? 0 : width;
	((width > 0 && !pm->t_flag.zero) || sign) ? space = 0 : 0;
	*len += width + (space ? 1 : 0) + (sign ? 1 : 0);
	if (!pm->t_flag.minus)
	{
		while (!pm->t_flag.zero && width-- > 0)
			ft_putchar(32);
		if (space || sign)
			ft_putchar(sign != 0 ? sign : space);
		while (pm->t_flag.zero && width-- > 0)
			ft_putchar(48);
	}
	else if (pm->t_flag.minus)
	{
		(pm->t_flag.space) ? (width -= 1) : 0;
		while (width-- > 0)
			ft_putchar(32);
	}
}

int			printf_float(va_list args, t_param *pm)
{
	int		len;
	char	*str;

	(pm->t_flag.dot != DOT) ? pm->precision = 6 : 0;
	if (pm->modifier & UPP_L)
		str = printf_lf(va_arg(args, long double), 10, pm);
	else
		str = printf_f(va_arg(args, double), 8, pm);
	str = rounding_float(str, pm->precision);
	len = ft_strlen(str);
	if (!pm->t_flag.minus)
		print_space_float(pm, &len, pm->t_flag.plus, pm->t_flag.space);
	if (pm->t_flag.minus)
		ft_putchar(pm->t_flag.plus ? pm->t_flag.plus : pm->t_flag.space);
	ft_putstr(str);
	if (pm->t_flag.minus)
		print_space_float(pm, &len, pm->t_flag.plus, pm->t_flag.space);
	free(str);
	return (len);
}
