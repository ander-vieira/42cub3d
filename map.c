/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:17:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 10:25:04 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_bool	map_init(t_map *map, t_lvec dim)
{
	map->tiles = (char *)malloc(sizeof(char) * dim.x * dim.y);
	if (map->tiles == NULL)
		return (FALSE);
	map->w = dim.x;
	map->h = dim.y;
	return (TRUE);
}

void	map_free(t_map *map)
{
	free(map->tiles);
	map->tiles = NULL;
}

t_bool	map_has(t_map *map, t_lvec pos)
{
	return (pos.x >= 0 && pos.x < map->w && pos.y >= 0 && pos.y < map->h);
}

char	map_get(t_map *map, t_lvec pos)
{
	return (map->tiles[pos.y * map->w + pos.x]);
}

void	map_set(t_map *map, t_lvec pos, char tile)
{
	map->tiles[pos.y * map->w + pos.x] = tile;
}

void	map_print(t_map *map)
{
	t_lvec	pos;
	char	c;

	pos.x = 0;
	while (pos.x < map->w)
	{
		pos.y = 0;
		while (pos.y < map->h)
		{
			c = map_get(map, pos);
			write(1, &c, 1);
			pos.y++;
		}
		write(1, "\n", 1);
		pos.x++;
	}
}
