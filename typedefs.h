/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:56:26 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/02 20:37:30 by andeviei         ###   ########.fr       */
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
typedef unsigned int	t_uint;
typedef unsigned int	t_color;
typedef char			*t_str;

typedef enum e_face
{
	//Forward / North
	FACE_F,
	//Right / East
	FACE_R,
	//Back / South
	FACE_B,
	//Left / West
	FACE_L
}						t_face;

typedef struct s_lvec
{
	long	x;
	long	y;
}						t_lvec;

typedef struct s_dvec
{
	double	x;
	double	y;
}						t_dvec;

typedef struct s_strl
{
	size_t	n;
	t_str	*strs;
}						t_strl;

typedef struct s_map
{
	char	*tiles;
	t_lvec	dim;
}						t_map;

typedef struct s_cubed
{
	t_str	tex_n;
	t_str	tex_e;
	t_str	tex_s;
	t_str	tex_w;
	t_color	color_f;
	t_color	color_c;
	t_map	map;
	t_lvec	pos;
	t_face	face;
}						t_cubed;

t_lvec	lvec_new(long x, long y);
t_lvec	lvec_add(t_lvec v1, t_lvec v2);

t_dvec	dvec_new(double x, double y);
t_dvec	dvec_add(t_dvec v1, t_dvec v2);
t_dvec	dvec_scl(t_dvec v, double scale);
t_dvec	dvec_trn(t_dvec v, t_face face);
t_dvec	dvec_rot(t_dvec v, double angle);

size_t	str_len(t_str str);
void	str_copy(t_str dest, t_str src, size_t len);

t_strl	split_strs(t_str str);

t_bool	map_init(t_map *map, t_lvec dim);
void	map_free(t_map *map);
char	map_get(t_map *map, t_lvec pos);
void	map_set(t_map *map, t_lvec pos, char tile);
void	map_print(t_map *map);

#endif
