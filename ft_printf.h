/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:29:54 by gartanis          #+#    #+#             */
/*   Updated: 2019/12/26 15:29:54 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     FT_PRINTF_H
# define    FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define PRINT_ERROR (-1)

# define SPECIFIER "cspdiouxXf"
# define SPEC_LEN (ft_strlen(SPECIFIER))

/* 
** double data structure
*/

typedef struct  s_param
{
    struct      s_flag
    {
        char    plus;
        char    minus;
        char    space;
        char    zero;
        char    hash;           
    }           t_flag;
    char        specifier;
    int         width;
    int         precision;
}               t_param;

/* 
** flags
*/

# define PLUS       ('+')
# define MINUS      ('-')
# define SPACE      (' ')
# define HASH       ('#')
# define ZERO       ('0')

/* 
** data type specifier
*/

# define SPEC_C     ('c')
# define SPEC_S     ('s')
# define SPEC_P     ('p')
# define SPEC_D     ('d')
# define SPEC_I     ('i')
# define SPEC_O     ('o')
# define SPEC_U     ('u')
# define SPEC_LOW_X ('x')
# define SPEC_UP_X  ('X')
# define SPEC_F     ('f')

/* 
** size modifiers
*/

# define MOD_LOW_H  ('h')
# define MOD_LOW_HH ('hh')
# define MOD_LOW_L  ('l')
# define MOD_LOW_LL ('ll')
# define MOD_UP_L   ('L')

/* 
** prototypes of basic functions
*/

int ft_printf(const char *format, ...);

int	pars_specifier(char *specif, t_param *param);

/* 
** print function prototypes
*/

int print_char(t_param *param, va_list args);
int print_string(t_param *param, va_list args);

#endif