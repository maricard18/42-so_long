# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maricard <maricard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:22:41 by maricard          #+#    #+#              #
#    Updated: 2023/03/10 12:30:36 by maricard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a
NAME = so_long
INCLUDES = includes

SRC = 	./src/MapValidations/extension_validations.c \
		./src/MapValidations/map_values.c \
		./src/MapValidations/map_validations.c \
		./src/Utils/utils.c \
		./src/Utils/struct_init.c \
		./src/Game/window.c 

SRC-OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(SRC-OBJ) $(LIBFT)
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) main.c $(SRC-OBJ) $(LIBFT) $(MLX) -o $(NAME) -I $(INCLUDES)
#	./so_long maps/Valid1.ber

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./mlx
	$(RM) $(SRC-OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all
