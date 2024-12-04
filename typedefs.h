/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:56:26 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/04 15:25:28 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

/* ************************************************************************** */
/* Common typedefs                                                            */
/* ************************************************************************** */

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

typedef struct s_ivec2
{
	size_t	x;
	size_t	y;
}						t_ivec2;

typedef struct s_vec2
{
	double	x;
	double	y;
}						t_vec2;

typedef struct s_map
{
	char	*tiles;
	t_uint	w;
	t_uint	h;
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

#endif
