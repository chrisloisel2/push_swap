# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clkuznie <lchristo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 21:59:06 by lchristo          #+#    #+#              #
#    Updated: 2021/03/14 20:35:35 by lchristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

LIB		=	libft.a

H		=	push_swap.h

SRC		=	main\
			setup\
			utils\
			help\
			rotate\
			reverse\
			ft_algo

O		=	$(addprefix src/, $(addsuffix .o, $(SRC)))

C		=	$(addprefix src/, $(addsuffix .c, $(SRC)))

CC		=	cc -Wall -Wextra -Werror

%.o: %.c
	$(CC) $I -c $< -o $@

all:
	@echo -n "\n\033[0;34mCompiling libft :\n"
	@$(MAKE) -C libft
	@echo -n "\n\033[1;32mlibft done\n"
	@echo -n "compilation libft completed\n"
	@echo -n "\n"
	@make $(NAME)

$(NAME): $O
	@echo -n "\n\033[0;34mCompiling...\n"
	gcc  -o  $@ $O libft/libft.a -o $(NAME)
	@echo -n "\n\033[1;32mpush_swap generated\n\n"


debug:
	@echo -n "\n\033[0;34mCompiling...\n"
	gcc -fsanitize=address -g3 -o $@ $C libft/libft.a -o $(NAME)
	@echo -n "\n\033[1;32mpush_swap generated\n\n"


clean:
	rm -rf $O
	@$(MAKE) -C libft clean

fclean: clean
	@$(MAKE) -C libft fclean

re:
	@echo -n "\n\033[0;34mCompiling...\n"
	cc -o $@ $O libft/libft.a -o $(NAME)
	@echo -n "\n\033[1;32mCUB3D generated\n\n"