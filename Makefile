# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gartanis <gartanis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 01:20:51 by gartanis          #+#    #+#              #
#    Updated: 2020/02/09 16:04:16 by gartanis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=		libftprintf.a
CC			= 		gcc
HEADER		=		includes/ft_printf.h
CFLAGS 		= 		-I includes/ -Wall -Werror -Wextra
OBJ 		= 		$(SRC:.c=.o)

C_OK		=		"\033[35m"
C_GOOD		=		"\033[32m"
C_NO		=		"\033[00m"

SUCCESS		=		$(C_GOOD)SUCCESS$(C_NO)
OK			=		$(C_OK)OK$(C_NO)

SRC =	srcs/ft_printf.c			\
		srcs/parse_specifier.c		\
		srcs/get_param.c			\
		srcs/print_txt.c			\
		srcs/print_hexadecimal.c	\
		srcs/print_nbr.c			\
		srcs/signed_nbr.c			\
		srcs/unsigned_nbr.c			\
		srcs/print_octal.c			\
		srcs/print_float.c			\
		srcs/util_fl/convers_fl.c	\
		srcs/util_fl/match_fl.c		\

all: $(NAME)

%.o: %.c
	@printf "[ft_printf] Compiling [.:]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[ft_printf] Compiling [:.]\r"

$(NAME): $(OBJ) $(HEADER)
	@make -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling & indexing" [ $(NAME) ] $(SUCCESS)

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@printf "[ft_printf] Removed object files!\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

re: fclean all

.PHONY: all clean fclean re