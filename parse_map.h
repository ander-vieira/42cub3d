/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:49:57 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/18 17:49:01 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include "typedefs.h"

# define LINE_BUFFER	1024

# define FILE_EXTENSION	".cub"

# define PREFIX_NORTH	"NO"
# define PREFIX_EAST	"EA"
# define PREFIX_SOUTH	"SO"
# define PREFIX_WEST	"WE"
# define PREFIX_FLOOR	"F"
# define PREFIX_CEILING	"C"

# define MAP_WALL		'1'
# define MAP_FLOOR		'0'
# define MAP_PLAYER_N	'N'
# define MAP_PLAYER_E	'E'
# define MAP_PLAYER_S	'S'
# define MAP_PLAYER_W	'W'
# define MAP_FLOOD		'F'

typedef struct s_parse
{
	t_cubed	*cubed;
	t_fd	fd;
	t_bool	is_map;
	t_strl	map_lines;
	t_str	line;
}	t_parse;

typedef struct s_valid
{
	t_cubed	*cubed;
	t_bool	ok;
	t_bool	has_player;
}	t_valid;

t_str	get_line(t_fd fd);

t_bool	is_texture(t_str prefix);
void	read_texture(t_cubed *cubed, t_str prefix, t_str value);

t_bool	is_color(t_str prefix);
t_bool	read_color(t_cubed *cubed, t_str prefix, t_str value);

void	process_map(t_map *map, t_strl lines);
t_bool	validate_map(t_cubed *cubed);

/* ************************************************************************** */
/* Module main function                                                       */
/* ************************************************************************** */

t_bool	parse_map(t_str file, t_cubed *cubed);

#endif
