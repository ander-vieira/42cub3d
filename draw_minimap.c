/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:28:27 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/21 11:56:44 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	draw_border(t_run *r)
{
	t_lvec	pos;

	pos.x = WIN_W - MMAP_SIZE - 2 * MMAP_BRDRS;
	while (pos.x < WIN_W)
	{
		pos.y = 0;
		while (pos.y < MMAP_SIZE + 2 * MMAP_BRDRS)
		{
			if (pos.x < WIN_W - MMAP_SIZE - MMAP_BRDRS
				|| pos.x >= WIN_W - MMAP_BRDRS
				|| pos.y < MMAP_BRDRS || pos.y >= MMAP_SIZE + MMAP_BRDRS)
				*(img_px(r->scr, pos)) = MMAP_BRDRC;
			pos.y++;
		}
		pos.x++;
	}
}

static t_lvec	tile_position(t_lvec pos)
{
	return (lvec_new(pos.x + WIN_W - MMAP_SIZE - MMAP_BRDRS,
			pos.y + MMAP_BRDRS));
}

static t_color	tile_color(t_map *map, t_lvec pos, t_dvec player)
{
	t_lvec	tile;

	tile = lvec_new(pos.x * map->dim.x / MMAP_SIZE,
			pos.y * map->dim.y / MMAP_SIZE);
	if (tile.x == floor(player.x) && tile.y == floor(player.y))
		return (MMAP_PLAYR);
	if (map_get(map, tile) == MAP_WALL)
		return (MMAP_WALL);
	return (MMAP_FLOOR);
}

void	draw_minimap(t_run *r)
{
	t_lvec	pos;

	draw_border(r);
	pos.x = 0;
	while (pos.x < MMAP_SIZE)
	{
		pos.y = 0;
		while (pos.y < MMAP_SIZE)
		{
			*(img_px(r->scr, tile_position(pos))) =
				tile_color(&(r->cub->map), pos, r->pos);
			pos.y++;
		}
		pos.x++;
	}
}
