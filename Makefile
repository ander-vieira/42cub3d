# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 22:26:20 by andeviei          #+#    #+#              #
#    Updated: 2025/01/18 15:06:12 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

SRCS =	cubed.c \
		dvec.c \
		get_line.c \
		handler_dstry.c \
		handler_keydn.c \
		handler_loop.c \
		img.c \
		lvec.c \
		map.c \
		mouse.c \
		parse_map.c \
		process_map.c \
		print_error.c \
		raycast.c \
		read_color.c \
		read_texture.c \
		run_window.c \
		split_strs.c \
		str.c \
		validate_map.c

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