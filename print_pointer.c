/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:51:39 by gartanis          #+#    #+#             */
/*   Updated: 2020/01/08 13:50:11 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_pointer(intptr_t ptr, char **sptr)
{
	char		*str;
	int			i;
	intptr_t	cptr;

	i = 0;
	cptr = ptr;
	while (cptr /= 0x10)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i += 3))))
		return (-1);
	str[i] = '\0';
	while (i-- >= 0)
	{
		if (ptr)
		{
			str[i] = "0123456789abcdef"[ptr % 0x10];
			ptr /= 0x10;
		}
		else
			str[i] = PREFIX[i];
	}
	*sptr = str;
	return (ft_strlen(str));
}

int			print_pointer(t_param *param, va_list args)
{
	intptr_t	ptr;
	char		*sptr;
	int			len;

	ptr = va_arg(args, intptr_t);
	if (ptr < 0)
		return (PRINT_ERROR);
	if ((len = get_pointer(ptr, &sptr)) == PRINT_ERROR)
		return (len);
	if (param->width && !(param->t_flag.minus == MINUS))
		print_space(param->width - len, SPACE);
	ft_putstr(sptr);
    free(sptr);
	if (param->width && param->t_flag.minus == MINUS)
		print_space(param->width - len, SPACE);
	return (len);
}
