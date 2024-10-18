/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:50:59 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/16 13:26:57 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

/* ************************************************************************** */
/* Library includes                                                           */
/* ************************************************************************** */

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* ************************************************************************** */
/* Other header includes                                                      */
/* ************************************************************************** */

# include "typedefs.h"
# include "parse_map.h"
# include "run_window.h"

/* ************************************************************************** */
/* Common function calls                                                      */
/* ************************************************************************** */

void	print_error(char *str);

t_bool	map_init(t_map *map, t_uint w, t_uint h);
void	map_free(t_map *map);
char	map_get(t_map *map, t_uint x, t_uint y);
void	map_set(t_map *map, t_uint x, t_uint y, char tile);
void	map_print(t_map *map);

t_vec2	vec2_init(double x, double y);
t_vec2	vec2_add(t_vec2 v1, t_vec2 v2);
t_vec2	vec2_sub(t_vec2 v1, t_vec2 v2);
double	vec2_scalar(t_vec2 v1, t_vec2 v2);
t_vec2	vec2_inv(t_vec2 v1);
t_vec2	vec2_normal(t_vec2 v1);

#endif