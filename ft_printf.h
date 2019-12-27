/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:48:52 by gartanis          #+#    #+#             */
/*   Updated: 2019/12/27 19:08:48 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

/*
** double data structure
*/

typedef struct			s_param
{
	struct				s_flag
	{
		char			plus;
		char			minus;
		char			space;
		char			zero;
		char			hash;
	}					t_flag;
	char				specifier;
	int					width;
	int					precision;
}						t_param;

# define PRINT_ERROR	(-1)
# define SPECIFIER		"cspdiouxXf"
# define SPEC_LEN		(ft_strlen(SPECIFIER))

/*
** flags
*/

# define PLUS			('+')
# define MINUS			('-')
# define SPACE			(' ')
# define HASH			('#')
# define ZERO			('0')

# define DOT			('.')
# define PERCENT		('%')

/*
** data type specifier
*/

# define SPEC_C			('c')
# define SPEC_S			('s')
# define SPEC_P			('p')
# define SPEC_D			('d')
# define SPEC_I			('i')
# define SPEC_O			('o')
# define SPEC_U			('u')
# define SPEC_LOW_X		('x')
# define SPEC_UP_X		('X')
# define SPEC_F			('f')

/*
** size modifiers
*/

# define MOD_LOW_H		('h')
# define MOD_LOW_HH		("hh")
# define MOD_LOW_L		('l')
# define MOD_LOW_LL		("ll")
# define MOD_UP_L		('L')

/*
** prototypes of basic functions
*/

int						ft_printf(const char *format, ...);
int						pars_specifier(const char *specif, t_param *param);
int						get_param(const char *pf, t_param *param);

/*
** prototypes print function
*/

void					print_space(int offset);
int						print_no_specifier(const char *pf);
int						print_char(t_param *param, va_list args);
int						print_string(t_param *param, va_list args);

#endif
