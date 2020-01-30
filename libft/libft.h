/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:32:58 by gartanis          #+#    #+#             */
/*   Updated: 2020/01/31 01:48:05 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_strrev(char *src);
long double			ft_power(long double nbr, int n);
char				*ft_dectostr(int *arr, int sign, int len);

#endif
