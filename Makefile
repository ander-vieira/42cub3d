# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 22:26:20 by andeviei          #+#    #+#              #
#    Updated: 2024/12/04 16:26:48 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

SRCS =	cubed.c \
		handler_dstry.c \
		handler_keydn.c \
		handler_loop.c \
		img.c \
		ivec2.c \
		map.c \
		parse_map.c \
		print_error.c \
		run_window.c \
		vec2.c

HDRS =	cubed.h \
		parse_map.h \
		run_window.h \
		typedefs.h

MLX_DIR = mlx/
MLX = mlx/libmlx_Linux.a

all: $(NAME)

$(NAME): $(MLX) $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(SRCS) $(MLX) -o $(NAME) -lm -lXext -lX11

$(MLX):
	make -C $(MLX_DIR) all

clean:
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS) $(HDRS)

.PHONY: all clean fclean re norm