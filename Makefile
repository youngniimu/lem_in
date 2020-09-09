#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thalme <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/08 09:59:18 by thalme            #+#    #+#              #
#    Updated: 2020/09/08 09:59:18 by thalme           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

SRC_DIR = src/
SRC = 	main.c \
		initialize_data.c \
		handle_input.c \
		make_graph.c \
		find_routes.c
LIB = libprintf/libftprintf.a
FLAGS = -Wall -Wextra -Werror


$(NAME): all

all:
	make -C libprintf
	gcc $(FLAGS) -o $(NAME) $(LIB) $(addprefix $(SRC_DIR), $(SRC))

clean:
	make -C libprintf clean


fclean: clean
	make -C libprintf fclean
	rm -rf $(NAME)

re: fclean all
