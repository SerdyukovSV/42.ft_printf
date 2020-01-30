/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:51:39 by gartanis          #+#    #+#             */
/*   Updated: 2020/01/31 01:06:41 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_space_hex(t_param *pm, int *len, int zero, char hash)
{
	int width;

	width = pm->width - (*len + zero + (hash ? 2 : 0));
	width = (width < 0) ? 0 : width;
	*len += width + zero + (hash ? 2 : 0);
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

int			get_hex_octal(uintmax_t hex, char **sptr, char spec)
{
	char		*str;
	int			i;
	uintmax_t	cphex;

	i = (spec == 'p') ? 3 : 1;
	cphex = hex;
	while (cphex /= (spec == 'o' ? 8 : 0x10))
		i++;
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (-1);
	str[i] = '\0';
	while (i-- >= 0)
	{
		if (hex && (spec == 'p' || spec == 'x'))
			str[i] = "0123456789abcdef"[hex % 0x10];
		else if (hex && spec == 'X')
			str[i] = "0123456789ABCDEF"[hex % 0x10];
		else if (hex && spec == 'o')
			str[i] = "012345678"[hex % 8];
		else if (!hex && spec == 'p')
			str[i] = PREFIX[i];
		hex /= (spec == 'o' ? 8 : 0x10);
	}
	*sptr = str;
	return (ft_strlen(str));
}

static int	print_hex(uintmax_t hex, t_param *pm)
{
	int		len;
	char	*str;
	int		count;
	int		zero;

	len = get_hex_octal(hex, &str, pm->specifier);
	zero = (pm->precision > len ? pm->precision - len : 0);
	if (!pm->t_flag.minus)
		print_space_hex(pm, &len, zero, pm->t_flag.hash);
	if (pm->t_flag.hash && pm->t_flag.minus)
		ft_putstr((pm->specifier == 'x') ? "0x" : "0X");
	count = 0;
	while (pm->t_flag.minus && count++ < zero)
		ft_putchar(48);
	ft_putstr(str);
	if (pm->t_flag.minus)
		print_space_hex(pm, &len, zero, pm->t_flag.hash);
	free(str);
	return (len);
}

static int	print_pointer(intptr_t ptr, t_param *pm)
{
	char		*sptr;
	int			len;

	if (ptr < 0)
		return (PRINT_ERROR);
	if ((len = get_hex_octal(ptr, &sptr, pm->specifier)) == PRINT_ERROR)
		return (len);
	if (pm->width && !(pm->t_flag.minus == MINUS))
		print_space(pm->width - len, SPACE);
	ft_putstr(sptr);
	free(sptr);
	if (pm->width && pm->t_flag.minus == MINUS)
		print_space(pm->width - len, SPACE);
	len += pm->width > len ? pm->width - len : 0;
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
