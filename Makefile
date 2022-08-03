# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 19:06:42 by stena-he          #+#    #+#              #
#    Updated: 2022/08/03 22:07:56 by stena-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
NAME = 	fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Removal
RM = rm -f

# Libraries
MLX = libraries/mlx/libmlx.a -framework OpenGL -framework AppKit
LIBFT = libraries/libft/libft.a
PRINTF = libraries/ft_printf/libftprintf.a

# Source and object files
SRC =	*.c\
		*.c
			
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re