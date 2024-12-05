/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:56:26 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 10:27:58 by andeviei         ###   ########.fr       */
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
	t_uint	color_f;
	t_uint	color_c;
	t_map	map;
	t_dvec	pos;
	t_dvec	dir;
}						t_cubed;

t_lvec	lvec_new(t_uint x, t_uint y);
t_lvec	lvec_add(t_lvec v1, t_lvec v2);

t_dvec	dvec_new(double x, double y);
t_dvec	dvec_add(t_dvec v1, t_dvec v2);
t_dvec	dvec_sub(t_dvec v1, t_dvec v2);
double	dvec_dot(t_dvec v1, t_dvec v2);
t_dvec	dvec_inv(t_dvec v1);
t_dvec	dvec_nrm(t_dvec v1);

t_bool	map_init(t_map *map, t_lvec dim);
void	map_free(t_map *map);
char	map_get(t_map *map, t_lvec pos);
void	map_set(t_map *map, t_lvec pos, char tile);
void	map_print(t_map *map);

#endif
