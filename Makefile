# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwebber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 17:06:25 by jwebber           #+#    #+#              #
#    Updated: 2019/10/16 17:21:16 by jwebber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_brute.c \
        ft_error.c \
        ft_fill_del.c \
        ft_lstsize.c \
        ft_normalize.c \
        ft_parser.c \
        ft_print_result.c \
        ft_swap.c \
        ft_tet_coordinate.c \
        get_next_line.c \
        main.c
OBJ = $(SRC:.c=.o)
FLAGS = #-Wall -Wextra -Werror
NAME = fillit

# libft
LIBFT_PATH = libft/
LIBFT_BIN = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_BIN)

.c.o:
		gcc -c -o $@ $< $(FLAGS)

$(NAME): $(OBJ) $(LIBFT)
	    gcc -o $@ $^ $(LIBFT) $(FLAGS)

.PHONY: $(LIBFT)

$(LIBFT):
	    $(MAKE) -C $(LIBFT_PATH)
	
all: $(NAME)
