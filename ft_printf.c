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
	/* else if (specif == SPEC_P)
		ret = print_pointer(param, args);
	else if (specif == SPEC_D || specif == SPEC_I)
		ret = print_decimal(param, args);
	else if (specif == SPEC_O)
		ret = print_octal(param, args);
	else if (specif == SPEC_LOW_X || specif == SPEC_UP_X)
		ret = print_hexadecimal(param, args);
	else
		ret = print_no_specifier(); */
	return (ret);
}

static	int		print_stdout(char *pf, va_list args)
{
	t_param param;
	int		ret;

	ret = PRINT_ERROR;
	param.t_flag.plus   = NULL;
	param.t_flag.minus  = NULL;
	param.t_flag.space  = NULL;
	param.t_flag.zero   = NULL;
	param.t_flag.hash   = NULL;
	param.width         = 0;
	param.precision     = -1;
	param.specifier     = NULL;
	if (!(*pf))
        return (ret);
    else if (pars_specifier(pf, &param) != PRINT_ERROR)
		return(print_printf(param.specifier, &param, args));
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	char	*pf;
	va_list args;
	int		ret;

	pf = format;
	ret = 1;
	va_start(args, format);
	while (*pf)
	{
		if (pf == '%')
		{
			pf++;
			if ((ret = print_stdout(pf, args)) != PRINT_ERROR);
				break ;
		}
		else
			ft_putchar(pf);
		pf++;
	}
	va_end(args);
	return (ret);
}
