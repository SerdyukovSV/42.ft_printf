/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:57:07 by gartanis          #+#    #+#             */
/*   Updated: 2019/09/28 02:36:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					neg;
	unsigned long int	res;

	res = 0;
	i = 0;
	neg = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
						&& (str[i] - '0') > 7)) && neg == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
						&& (str[i] - '0') > 8)) && neg == -1)
			return (0);
		res = res * 10 + str[i] - 48;
		i++;
	}
	return ((int)res * neg);
}
