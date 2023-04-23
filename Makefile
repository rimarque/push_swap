# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rimarque <rimarque>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 13:48:58 by rimarque          #+#    #+#              #
#    Updated: 2023/04/23 18:03:51 by rimarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./libftx/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

OBJ = src/aux_main.o \
	src/aux_stack.o \
	src/check_error.o \
	src/ops/push.o \
	src/ops/rotate.o \
	src/ops/swap.o \

OBJ_MAND = src_mandatory/push_swap.o \
	src_mandatory/algorithm.o \
	src_mandatory/sort3.o \
	src_mandatory/costs.o \
	src_mandatory/aux.o \
	src_mandatory/aux_find.o \
	src_mandatory/aux_move.o

OBJ_BONUS = src_bonus/checker.o \
			src_bonus/aux_checker.o

all: $(NAME)

$(LIBFT):
	echo "compiling..."
	$(MAKE) -C ./libftx
	echo "LIBFT created"

$(NAME): $(OBJ_MAND) $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_MAND) $(OBJ) $(LIBFT) -o $(NAME)
	echo "Program READY"

bonus: $(OBJ_BONUS) $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ_BONUS) $(OBJ) $(LIBFT) -o checker
		echo "Program checker READY"

clean:
	$(MAKE) -C ./libftx
	rm -rf $(OBJ)
	rm -rf $(OBJ_MAND)
	rm -rf $(OBJ_BONUS)
	echo "Object files CLEAN"

fclean: clean
	$(MAKE) fclean -C ./libftx
	rm -rf $(NAME)
	rm -rf checker
	echo "All files CLEAN"

re: fclean all

bre: fclean bonus

.SILENT:

.PHONY: all clean fclean re
