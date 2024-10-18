/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:17:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/18 14:12:46 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_bool	map_init(t_map *map, t_uint w, t_uint h)
{
	map->tiles = (char *)malloc(sizeof(char) * w * h);
	if (map->tiles == NULL)
		return (FALSE);
	map->w = w;
	map->h = h;
	return (TRUE);
}

void	map_free(t_map *map)
{
	free(map->tiles);
	map->tiles = NULL;
}

char	map_get(t_map *map, t_uint x, t_uint y)
{
	if (x >= map->w || y >= map->h)
		return ('\0');
	return (map->tiles[y * map->w + x]);
}

void	map_set(t_map *map, t_uint x, t_uint y, char tile)
{
	if (x >= map->w || y >= map->h)
		return ;
	map->tiles[y * map->w + x] = tile;
}

void	map_print(t_map *map)
{
	char	c;
	t_uint	x;
	t_uint	y;

	x = 0;
	while (x < map->w)
	{
		y = 0;
		while (y < map->h)
		{
			c = map_get(map, x, y);
			write(1, &c, 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
}
