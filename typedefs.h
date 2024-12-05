/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:56:26 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 10:11:29 by andeviei         ###   ########.fr       */
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
	int		color_f;
	int		color_c;
	t_map	map;
	t_dvec	pos;
	t_dvec	dir;
}						t_cubed;

#endif
