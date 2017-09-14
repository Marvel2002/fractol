# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/14 18:49:59 by mmatime           #+#    #+#              #
#    Updated: 2017/09/14 19:07:56 by mmatime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = ./src/main.c ./src/burningship.c ./src/error.c ./src/inits.c ./src/keys.c ./src/mandelbrot.c ./src/draw.c ./src/expose.c ./src/julia.c ./src/mouse.c
LIB_PATH = ./libft
MLX_PATH = ./minilibx
SRC_PATH = ./src/
INCLUDES = -I./includes -I$(LIB_PATH)
LIB_BIN = $(LIB_PATH)/libft.a
MLX_BIN = $(MLX_PATH)/libmlx.a
FLAG = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
CC = gcc

$(NAME): $(OBJ)
	make -C $(LIB_PATH)
	make -C $(MLX_PATH)
	$(CC) -o $(NAME) $(SRC) $(INCLUDES) $(LIB_BIN) -L$(MLX_PATH) -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

clean:
	make -C $(LIB_PATH) clean
	make -C $(MLX_PATH) clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C $(LIB_PATH) fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
