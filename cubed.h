/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:50:59 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 10:11:24 by andeviei         ###   ########.fr       */
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

t_lvec ivec2_new(t_uint x, t_uint y);
t_lvec ivec2_add(t_lvec v1, t_lvec v2);

t_dvec	vec2_init(double x, double y);
t_dvec	vec2_add(t_dvec v1, t_dvec v2);
t_dvec	vec2_sub(t_dvec v1, t_dvec v2);
double	vec2_scalar(t_dvec v1, t_dvec v2);
t_dvec	vec2_inv(t_dvec v1);
t_dvec	vec2_normal(t_dvec v1);

#endif