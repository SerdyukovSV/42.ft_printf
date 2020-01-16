#include "ft_printf.h"

double  power(double nbr, long n)
{
    if (n == 0)
        return (1);
    if (n < 0)
        return (power(1.0/nbr, -n));
    return (nbr * power(nbr, n - 1));
}