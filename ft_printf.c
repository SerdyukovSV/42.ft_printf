/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:24:07 by gartanis          #+#    #+#             */
/*   Updated: 2019/12/26 16:24:17 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_printf(char specif, t_param *param, va_list args)
{
	int ret;

	ret = 0;
	if (specif == SPEC_C)
		ret = print_char(param, args);
	else if (specif == SPEC_S)
		ret = print_string(param, args);
	else if (specif == SPEC_P)
		ret = print_pointer(param, args);
	/* else if (specif == SPEC_D || specif == SPEC_I)
		ret = print_decimal(param, args);
	else if (specif == SPEC_O)
		ret = print_octal(param, args);
	else if (specif == SPEC_LOW_X || specif == SPEC_UP_X)
		ret = print_hexadecimal(param, args);
	else
		ret = print_no_specifier(); */
	return (ret);
}

static	int		print_stdout(const char *pf[], va_list args)
{
	// printf("print_stdout\n"); //////////////////////////////////////////
	t_param param;
	int		ret;

	param.t_flag.plus   = 0;
	param.t_flag.minus  = 0;
	param.t_flag.space  = 0;
	param.t_flag.zero   = 0;
	param.t_flag.hash   = 0;
	param.width         = 0;
	param.precision     = 0;
	param.specifier     = 0;
	param.t_flag.dot	= 0;
	param.modifier		= 0;
	if (!(*pf))
        return (PRINT_ERROR);
    else if ((pars_specifier(pf, &param)) != PRINT_ERROR)
		return(print_printf(param.specifier, &param, args));
	return (print_percent(pf));
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	int		len_fm;
	int		len_arg;

	len_fm = 0;
	len_arg = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if ((len_arg = print_stdout(&format, args)) == PRINT_ERROR)
				break ;
		}
		else
		{
			// printf("*format = %c\n", *format); /////////////////////////////
			ft_putchar(*format);
			format++;
			len_fm++;
		}
	}
	va_end(args);
	return (len_fm + len_arg);
}
