/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:51:39 by gartanis          #+#    #+#             */
/*   Updated: 2020/02/02 23:43:16 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_space_hex(t_param *pm, int *len, int zero, char hash)
{
	int width;

	width = pm->width - (*len + zero + (hash ? 2 : 0));
	width = (width < 0) ? 0 : width;
	*len += width + zero + (hash ? 2 : 0);
	(pm->t_flag.dot == 1 && pm->width) ? width += 1 : 0;
	if (!pm->t_flag.minus)
	{
		while (!pm->t_flag.zero && width-- > 0)
			ft_putchar(32);
		if (hash)
			ft_putstr((pm->specifier == 'x') ? "0x" : "0X");
		while (pm->t_flag.zero && !zero && width-- > 0)
			ft_putchar(48);
		while (zero-- > 0)
			ft_putchar(48);
	}
	else if (pm->t_flag.minus)
		while (width-- > 0)
			ft_putchar(32);
}

static char	*get_hex(uintmax_t hex, char spec)
{
	char		*str;
	int			i;
	uintmax_t	k;

	i = ft_unbrlen(hex, 0x10);
	k = (spec == 'p') ? 2 : 0;
	if (!(str = (char *)malloc(sizeof(char) * (i + k + 1))))
		return (0);
	str[i + k] = '\0';
	while (i-- > 0)
	{
		if (spec == 'p' || spec == 'x')
			str[i] = "0123456789abcdef"[hex % 0x10];
		else if (spec == 'X')
			str[i] = "0123456789ABCDEF"[hex % 0x10];
		hex /= 0x10;
	}
	while (k-- > 0 && spec == 'p')
		str[k] = PREFIX[k];
	return (str);
}

static int	print_hex(uintmax_t hex, t_param *pm)
{
	int		len;
	char	*str;
	int		count;
	int		zero;
	int		dot;

	dot = ((hex == 0) && pm->t_flag.dot && !pm->precision) ? 1 : 0;
	dot ? pm->t_flag.dot = 1 : 0;
	str = get_hex(hex, pm->specifier);
	len = ft_strlen(str);
	zero = (pm->precision > len ? pm->precision - len : 0);
	if (!pm->t_flag.minus)
		print_space_hex(pm, &len, zero, (hex != 0) ? pm->t_flag.hash : 0);
	if (pm->t_flag.hash && (hex != 0) && pm->t_flag.minus)
		ft_putstr((pm->specifier == 'x') ? "0x" : "0X");
	count = 0;
	while (pm->t_flag.minus && count++ < zero)
		ft_putchar(48);
	ft_putstr((!dot) ? str : 0);
	if (pm->t_flag.minus)
		print_space_hex(pm, &len, zero, pm->t_flag.hash);
	(dot && !pm->width) ? len = 0 : 0;
	free(str);
	return (len);
}

static int	print_pointer(intptr_t ptr, t_param *pm)
{
	char		*str;
	int			len;

	if (ptr < 0)
		return (PRINT_ERROR);
	str = get_hex(ptr, pm->specifier);
	len = ft_strlen(str);
	if (pm->width && !(pm->t_flag.minus == MINUS))
		print_space(pm->width - len, SPACE);
	ft_putstr(str);
	if (pm->width && pm->t_flag.minus == MINUS)
		print_space(pm->width - len, SPACE);
	len += pm->width > len ? pm->width - len : 0;
	free(str);
	return (len);
}

int			print_hexadecimal(t_param *pm, va_list args)
{
	int len;

	len = 0;
	if (pm->modifier & H)
		len = print_hex((unsigned short)va_arg(args, unsigned int), pm);
	else if (pm->modifier & HH)
		len = print_hex((unsigned char)va_arg(args, unsigned int), pm);
	else if (pm->modifier & L)
		len = print_hex(va_arg(args, unsigned long), pm);
	else if (pm->modifier & LL)
		len = print_hex(va_arg(args, unsigned long long), pm);
	else if (pm->specifier == 'p')
		len = print_pointer(va_arg(args, intptr_t), pm);
	else
		len = print_hex(va_arg(args, unsigned int), pm);
	return (len);
}
