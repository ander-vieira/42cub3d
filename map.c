/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:17:25 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/21 00:53:47 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_bool	map_init(t_map *map, t_lvec dim)
{
	map->tiles = (char *)malloc(sizeof(char) * dim.x * dim.y);
	if (map->tiles == NULL)
		return (print_error(NULL), FALSE);
	map->dim = dim;
	return (TRUE);
}

void	map_free(t_map *map)
{
	free(map->tiles);
	map->tiles = NULL;
}

char	map_get(t_map *map, t_lvec pos)
{
	if (pos.x < 0 || pos.x >= map->dim.x || pos.y < 0 || pos.y >= map->dim.y)
		return (MAP_FLOOR);
	return (map->tiles[pos.y * map->dim.x + pos.x]);
}

void	map_set(t_map *map, t_lvec pos, char tile)
{
	map->tiles[pos.y * map->dim.x + pos.x] = tile;
}

void	map_foreach(t_map *map, void (*f)(t_map *, t_lvec, void *), void *ptr)
{
	t_lvec	pos;

	pos.y = 0;
	while (pos.y < map->dim.y)
	{
		pos.x = 0;
		while (pos.x < map->dim.x)
		{
			f(map, pos, ptr);
			pos.x++;
		}
		pos.y++;
	}
}
