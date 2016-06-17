# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: telain <telain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/22 17:19:39 by telain            #+#    #+#              #
#    Updated: 2016/06/15 17:26:55 by telain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
PATH_SRC = src/
PATH_INC = ./libft/includes/

CC = gcc
FLAGS = -Wall -Wextra -Werror

HEAD = includes/fdf.h

SRC = main.c\
	  draw.c\
	  input.c\

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@printf "Compiling $(NAME) ...\n"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@printf "fractol compiled\n"

%.o: %.c
	@$(CC) $(FLAGS) $(HEADERS) -c -o $@ $^
	@printf "[\e[32mfractol object\e[0m]\e[32m--\e[0m--\e[32m--\e[0m> : $@"
	@printf "\e[0m\n"

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
