# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maricard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:22:41 by maricard          #+#    #+#              #
#    Updated: 2023/02/20 11:31:02 by maricard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
LIBFT = ./libft/libft.a

SRC = ./MapValidations/extension_validations.c ./MapValidations/map_array.c \

SRC-OBJ = $(SRC:.c=.o)

NAME = so_long

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME):
	$(CC) $(CFLAGS) $(SRC-OBJ) $(LIBFT) main.c

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(SRC-OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all
