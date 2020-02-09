# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 22:24:34 by gartanis          #+#    #+#              #
#    Updated: 2020/02/09 16:17:08 by gartanis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CFLAGS		=	-Wall -Werror -Wextra -I. -c
FILES		=	ft_strchr.c			\
				ft_strchrpos.c		\
				ft_strlen.c			\
				ft_atoi.c			\
				ft_isdigit.c		\
				ft_isalpha.c		\
				ft_putchar.c		\
				ft_putstr.c			\
				ft_strcpy.c			\
				ft_strncpy.c		\
				ft_strcmp.c			\
				ft_strdup.c			\
				ft_memalloc.c		\
				ft_imemset.c		\
				ft_memset.c			\
				ft_memcpy.c			\
				ft_strcat.c			\
				ft_dectostr.c		\
				ft_power.c			\
				ft_strrev.c
OBJ		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
		gcc $(CFLAGS) libft.h $(FILES)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
