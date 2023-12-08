# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maricard <maricard@student.porto.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:22:41 by maricard          #+#    #+#              #
#    Updated: 2023/12/08 02:58:12 by maricard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS = $(shell uname)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

MLX_FLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11 -lm
MLX = mlx_linux
LIBFT = ./libft/libft.a
NAME = so_long
INCLUDES = includes

ifeq ($(OS), Darwin)
	MLX = mlx_macos
	MLX_FLAGS = -L $(MLX) -lmlx -framework OpenGL -framework AppKit -lm
endif

SRC = 	./src/MapValidations/extension_validations.c \
		./src/MapValidations/map_values.c \
		./src/MapValidations/map_validations.c \
		./src/MapValidations/path_validation.c \
		./src/Game/load_game.c \
		./src/Game/start_game.c \
		./src/Utils/error.c \
		./src/Utils/struct_init.c \
		./src/Utils/destroy.c

SRC-OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(SRC-OBJ) $(LIBFT)
	$(MAKE) -C $(MLX)
	$(CC) $(CFLAGS) main.c $(SRC-OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME) -I $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C $(MLX)
	$(RM) $(SRC-OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

leaks:
	valgrind --leak-check=full ./$(NAME) $(ARGS)
	
re: fclean all
