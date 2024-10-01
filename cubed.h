/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:50:59 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/01 13:29:28 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "mlx/mlx.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}						t_bool;

typedef int				t_fd;
typedef unsigned char	t_byte;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;
typedef char			*t_str;

typedef struct s_vec2
{
	double	x;
	double	y;
}						t_vec2;

typedef struct s_map
{
	char	*tiles;
	t_uint	x;
	t_uint	y;
}						t_map;

typedef struct s_cubed
{
	t_str	tex_n;
	t_str	tex_e;
	t_str	tex_s;
	t_str	tex_w;
	int		color_f;
	int		color_c;
	t_map	map;
	t_vec2	pos;
	t_vec2	dir;
}						t_cubed;

void	print_error(char *str);

t_bool	parse_map(t_str file, t_cubed *cubed);
void	run_window(t_cubed *cubed);

#endif