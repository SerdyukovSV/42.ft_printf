/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imemset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:45:18 by gartanis          #+#    #+#             */
/*   Updated: 2020/02/04 04:22:52 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_imemset(void *b, int c, size_t len)
{
	int *p;

	if (len == 0)
		return (b);
	p = b;
	while (len--)
	{
		*p = c;
		if (len)
			p++;
	}
	return (b);
}
