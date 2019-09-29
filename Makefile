# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwebber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 17:06:25 by jwebber           #+#    #+#              #
#    Updated: 2019/09/29 14:52:42 by jwebber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  get_next_line.c \
	  ft_usage.c

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
	@$(MAKE) re -C $(LIBFT_PATH)
