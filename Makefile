# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 22:26:20 by andeviei          #+#    #+#              #
#    Updated: 2024/10/01 13:33:06 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

SRCS = cubed.c parse_map.c print_error.c run_window.c
HDRS = cubed.h

MLX_DIR = mlx/
MLX = mlx/libmlx_Linux.a

all: $(NAME)

$(NAME): $(MLX) $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(SRCS) $(MLX) -o $(NAME) -lXext -lX11

$(MLX):
	make -C $(MLX_DIR) all

clean:
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re