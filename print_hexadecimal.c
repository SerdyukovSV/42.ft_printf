/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:51:39 by gartanis          #+#    #+#             */
/*   Updated: 2020/01/12 22:15:50 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_flags2(char *ch1, int n1, char *ch2, int n2, char *ch3, int n3)
{
    int i;

    i = 0;
    while (ch1 && i < n1)
	{
		if (ft_strlen(ch1) > 1)
        	ft_putchar(ch1[i]);
		else
			ft_putchar(*ch1);
		i++;
	}
    i = 0;
    while (ch2 && i < n2)
	{
        if (ft_strlen(ch2) > 1)
        	ft_putchar(ch2[i]);
		else
			ft_putchar(*ch2);
		i++;
	}
    i = 0;
    while (ch3 && i < n3)
	{
        if (ft_strlen(ch3) > 1)
        	ft_putchar(ch3[i]);
		else
			ft_putchar(*ch3);
		i++;
	}
}

static int	get_hexadecimal(uintmax_t hex, char **sptr, t_param *param)
{
	char		*str;
	int			i;
	uintmax_t	cphex;

	i = 0;
	cphex = hex;
	while (cphex /= 0x10)
		i++;
	i += param->specifier == 'p' ? 3 : 1;
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (-1);
	str[i] = '\0';
	while (i-- >= 0)
	{
		if (hex)
		{
			if (param->specifier == 'p' || param->specifier == 'x')
				str[i] = "0123456789abcdef"[hex % 0x10];
			else if (param->specifier == 'X')
				str[i] = "0123456789ABCDEF"[hex % 0x10];
			hex /= 0x10;
		}
		else if (param->specifier == 'p')
			str[i] = PREFIX[i];
	}
	*sptr = str;
	return (ft_strlen(str));
}

static int	unsigned_hex(uintmax_t hex, t_param *param)
{
	int len;
	char *str;
	int pref;
	int len_sp;
	char prefix[2] = "0x";

	pref = param->t_flag.hash == '#' ?	2 : 0;
	len = get_hexadecimal(hex, &str, param);
	len_sp = param->width - len - pref - (param->precision - len);
	if (!param->t_flag.minus && (param->width || param->t_flag.dot))
    {
        if (param->t_flag.zero && !param->t_flag.dot)
			print_flags2(param->specifier == 'X' ? "0X" : PREFIX, pref, "0", len_sp, 0, 0);
        else if (param->t_flag.dot)
            print_flags2(" ", len_sp, param->specifier == 'X' ? "0X" : \
				PREFIX, pref, "0", param->precision - len);
        else
            print_flags2(" ", len_sp, param->specifier == 'X' ? "0X" : PREFIX, pref, 0, 0);
    }
    // else if (param->t_flag.dot || param->t_flag.plus || param->t_flag.space)
    //     print_flags(csign, 1, '0', param->precision - len, 0, 0);
    ft_putstr(str);
    if (param->t_flag.minus)
        print_flags(' ', len_sp - (((param->precision - len) < 0) ? \
            0 : param->precision - len), 0, 0, 0, 0);
    free(str);

	return(len);
}

static int	print_pointer(intptr_t ptr, t_param *param)
{
	// intptr_t	ptr;
	char		*sptr;
	int			len;

	// ptr = va_arg(args, intptr_t);
	if (ptr < 0)
		return (PRINT_ERROR);
	if ((len = get_hexadecimal(ptr, &sptr, param)) == PRINT_ERROR)
		return (len);
	if (param->width && !(param->t_flag.minus == MINUS))
		print_space(param->width - len, SPACE);
	ft_putstr(sptr);
    free(sptr);
	if (param->width && param->t_flag.minus == MINUS)
		print_space(param->width - len, SPACE);
	return (len);
}

int			print_hexadecimal(t_param *param, va_list args)
{
	int len;

	len = 0;
	if (param->modifier & H)
		len = unsigned_hex((unsigned short)va_arg(args, unsigned int), param);
	else if (param->modifier & HH)
		len = unsigned_hex((unsigned char)va_arg(args, unsigned int), param);
	else if (param->modifier & L)
		len = unsigned_hex(va_arg(args, unsigned long), param);
	else if (param->modifier & LL)
		len = unsigned_hex(va_arg(args, unsigned long long), param);
	else if (param->specifier == 'p')
		len = print_pointer(va_arg(args, intptr_t), param);
	else
		len = unsigned_hex(va_arg(args, unsigned int), param);

	return (len);
}