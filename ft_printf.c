#include "ft_printf.h"

/* int valid_type(char *specif, va_list args)
{
    size_t type;

} */
int print_printf(char specif, t_param *param, va_list args)
{
    int ret;

    ret = 0;
    if (specif == )
}

void    print_offset(int offset)
{
    int i;

    i = 0;
    while (i++ < offset)
        ft_putchar(' ');
}

int pars_specifier(char *specif, va_list args)
{
    t_param parameters;
    
    if ((parameters.offset = ft_atoi(specif)) > 0)
        print_offset(parameters.offset);
    while (*specif)
    {
        if ((parameters.specifier = ft_strchr(SPECIFIER, *specif)))
            break ;
        specif++;
    }
    return (print_printf(parameters.specifier, &parameters, args));
}

int ft_printf(const char *format, ...)
{
    char    *pf;
    va_list args;

    pf = format;
    va_start(args, format);
    while (*pf)
    {
        if (pf != '%')
            ft_putchar(pf);
        else
            pars_specifier(pf++, args);
    }
    
}