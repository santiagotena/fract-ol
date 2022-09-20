# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 19:06:42 by stena-he          #+#    #+#              #
#    Updated: 2022/09/21 00:59:06 by stena-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
NAME = 	fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
DEBUG = -fsanitize=address

# Removal
RM = rm -f

# Libraries
MLX = libraries/mlx/libmlx.a -framework OpenGL -framework AppKit
LIBFT = libraries/ft_printf/libft/libft.a
PRINTF = libraries/ft_printf/libftprintf.a

# Source and object files
SRC =	src/main.c \
		src/mandelbrot.c \
		src/julia.c \
		src/window.c \
		src/utils.c \
		src/help.c
			
OBJ = $(SRC:%.c=%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libraries/mlx
	$(MAKE) -C libraries/ft_printf
	$(MAKE) -C libraries/ft_printf/libft
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
#	$(MAKE) clean -C libraries/mlx
	$(MAKE) clean -C libraries/ft_printf
	$(MAKE) clean -C libraries/ft_printf/libft
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(MAKE) fclean -C libraries/ft_printf
	$(MAKE) fclean -C libraries/ft_printf/libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re