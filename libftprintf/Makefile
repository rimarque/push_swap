# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rimarque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 14:39:30 by rimarque          #+#    #+#              #
#    Updated: 2023/03/22 15:30:38 by rimarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  libft/ft_bzero.c \
           libft/ft_isalnum.c \
           libft/ft_isalpha.c \
           libft/ft_isascii.c \
           libft/ft_isdigit.c \
           libft/ft_isprint.c \
           libft/ft_memset.c \
           libft/ft_strlen.c \
           libft/ft_memcpy.c \
           libft/ft_memmove.c \
           libft/ft_strlcpy.c \
           libft/ft_strlcat.c \
           libft/ft_toupper.c \
           libft/ft_tolower.c \
           libft/ft_strchr.c \
           libft/ft_strrchr.c \
           libft/ft_strncmp.c \
           libft/ft_memchr.c \
           libft/ft_memcmp.c \
           libft/ft_strnstr.c \
           libft/ft_atoi.c \
           libft/ft_calloc.c \
           libft/ft_strdup.c \
           libft/ft_substr.c \
           libft/ft_strjoin.c \
           libft/ft_strtrim.c \
           libft/ft_strmapi.c \
           libft/ft_striteri.c \
           libft/ft_putchar_fd.c \
           libft/ft_putstr_fd.c \
           libft/ft_putendl_fd.c \
           libft/ft_putnbr_fd.c \
           libft/ft_itoa.c \
           libft/ft_split.c \
	   printf/ft_print_cs.c \
	   printf/ft_print_iduxXp.c \
	   printf/ft_printf.c


NAME = libftprintf.a

CC = cc

CFLAGS  = -Wall -Wextra -Werror

RM = rm -rf

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@$(RM) a.out
	@$(RM) libft.h.gch
	@$(RM) libft.so

fclean: clean
	@$(RM) $(NAME)

re: fclean all
        
.PHONY: all clean fclean re
