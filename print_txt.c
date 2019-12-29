/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_txt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 20:47:18 by gartanis          #+#    #+#             */
/*   Updated: 2019/12/29 18:41:36 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_string(t_param *param, va_list args)
{
    char *src;
    char *dst;

    src = va_arg(args, char *);
    if (param->width && (!param->t_flag.minus))
        print_space((param->width - (ft_strlen(src))));
    if (param->precision >= 0)
        if ((dst = ft_strncpy(dst, src, ft_strlen(src))))
            src = dst;
    ft_putstr(src);
    if (param->width && (param->t_flag.minus))
        print_space((param->width - ft_strlen(src)));
    return (ft_strlen(src));
}

int print_char(t_param *param, va_list args)
{}