#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define PRINT_ERROR (-1)

# define SPECIFIER "csp"
# define SPEC_LEN (ft_strlen(SPECIFIER))

typedef struct  s_param
{
    char specifier;
    int offset;
}               t_param;

# define PLUS (+)
# define MINUS (-)
# define SPACE (' ')
# define HASH ('#')
# define ZERO ('0')

# define SPEC_C ('c')
# define SPEC_S ('s')
# define SPEC_P ('p')
# define SPEC_D ('d')
# define SPEC_I ('i')
# define SPEC_F ('f')




int print_char(t_param param, va_list args);
int print_string(t_param param, va_list args);

#endif