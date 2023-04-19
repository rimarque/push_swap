# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 13:48:58 by rimarque          #+#    #+#              #
#    Updated: 2023/04/19 15:36:03 by rimarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./libftprintf/libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = src/push_swap.c \
	src/list.c \
	src/check_error.c \
	src/ops/push.c \
	src/ops/rotate.c \
	src/ops/swap.c \
	src/algorithm/algorithm.c \
	src/algorithm/sort3.c \
	src/algorithm/costs.c \
	src/algorithm/aux.c \
	src/algorithm/aux_find.c \
	src/algorithm/aux_move.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(LIBFT):
	echo "compiling..."
	$(MAKE) -C ./libftprintf

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	echo "Object files READY"

clean:
	$(MAKE) -C ./libftprintf
	rm -rf $(OBJ)
	echo "Object files CLEAN"

fclean: clean
	$(MAKE) fclean -C ./libftprintf
	rm -rf $(NAME)
	echo "All files CLEAN"

re: fclean all

.SILENT:

.PHONY: all clean fclean re
