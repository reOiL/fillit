# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwebber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 17:06:25 by jwebber           #+#    #+#              #
#    Updated: 2019/10/29 15:41:39 by jwebber          ###   ########.fr        #
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
        main.c \
		ft_parser2.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

NAME = fillit

LIBFT_PATH = libft/

LIBFT = libft.a

.c.o:
	@gcc $(FLAGS) -c $< -o $@
	@printf "\e[32m😲 😲 😲  build success \e[36m$<\n"

$(NAME): $(OBJ) $(LIBFT_PATH)$(LIBFT)
	@gcc $(FLAGS) $(OBJ) $(LIBFT_PATH)$(LIBFT) -o $(NAME)
	@printf "\e[36m 🏁  👍  👍  👍  $(NAME) 👍  👍  👍  🏁  !\n"

$(LIBFT_PATH)$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

all: $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(RM) $(OBJ)
	@printf "\e[33mCleaned 😵 😵 😵 😵  !!!\n"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME)
	@printf "\e[31mFull cleaned 💀 💀 💀 💀  !!!\n"

re: fclean all
