# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maricard <maricard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:22:41 by maricard          #+#    #+#              #
#    Updated: 2023/03/07 12:37:44 by maricard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX = -Imlx
RM = rm -rf
LIBFT = ./libft/libft.a
NAME = so_long
INCLUDES = includes

SRC = 	./src/MapValidations/extension_validations.c \
		./src/MapValidations/map_values.c \
		./src/MapValidations/map_validations.c \
		./src/Utils/utils.c	

SRC-OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(SRC-OBJ) $(LIBFT)
	$(CC) $(CFLAGS) main.c $(SRC-OBJ) $(LIBFT) -o $(NAME) -I $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX) -c $< -o $@ -I $(INCLUDES)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(SRC-OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all
