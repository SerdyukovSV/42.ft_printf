/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:48:52 by gartanis          #+#    #+#             */
/*   Updated: 2020/01/13 19:56:30 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

#include <stdio.h>

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
		char			dot;
	}					t_flag;
	int					modifier;	
	char				specifier;
	int					width;
	int					precision;
}						t_param;

# define PRINT_ERROR	(-1)
# define SPECIFIER		"cCsSpdDioOuUxXf"
# define FLAGS			"+- #0."
# define PREFIX 		"0x"
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

# define H				(1)
# define HH				(2)
# define L				(4)
# define LL				(8)
# define UPP_L			(16)
# define UPP_D			(32)

/*
** prototypes of basic functions
*/

int						ft_printf(const char *format, ...);
int						pars_specifier(const char **specif, t_param *param);
int						get_param(const char **pf, t_param *param);
char    				verif_sign(t_param *param, intmax_t nbr);
void    				print_flags(char ch1, int n1, char ch2, \
									int n2, char ch3, int n3);
void					print_flags2(char *ch1, int n1, char *ch2, int n2, char *ch3, int n3);
int						get_hexadecimal(uintmax_t hex, char **sptr, t_param *param);

/*
** prototypes print function
*/

void					print_space(int offset, char flag);
int						print_percent(const char **pf);
int						print_char(t_param *param, va_list args);
int						print_string(t_param *param, va_list args);
int						print_hexadecimal(t_param *param, va_list args);
int						print_octal(t_param *param, va_list args);
int 					print_decimal(t_param *param, va_list args);
int  					print_signed(intmax_t nbr, t_param *param);
int  					print_unsigned(uintmax_t nbr, t_param *param);

#endif
