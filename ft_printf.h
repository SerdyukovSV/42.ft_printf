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


#endif