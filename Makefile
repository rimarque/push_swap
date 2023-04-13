# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rimarque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 13:48:58 by rimarque          #+#    #+#              #
#    Updated: 2023/04/08 12:57:24 by rimarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./libftprintf/libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = src/push_swap.c \
	src/list.c \
	src/check_error.c \
	src/ops/swap.c \
	src/ops/push.c \
	src/ops/rotate.c \
	src/sort3.c \
	src/algorithm.c \
	src/find_cheap.c

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
