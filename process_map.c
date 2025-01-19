/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:55:46 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/18 15:23:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	process_map_f(t_map *map, t_lvec pos, void *ptr)
{
	t_strl			*lines;
	static t_bool	eol;
	char			c;

	lines = ptr;
	if (pos.x == 0)
		eol = FALSE;
	if (!eol)
	{
		c = lines->strs[pos.y][pos.x];
		if (c == '\0' || c == '\n')
		{
			eol = TRUE;
			map_set(map, pos, MAP_FLOOR);
		}
		else if (c == ' ')
			map_set(map, pos, MAP_FLOOR);
		else
			map_set(map, pos, c);
	}
	else
		map_set(map, pos, MAP_FLOOR);
}

void	process_map(t_map *map, t_strl lines)
{
	map_foreach(map, &process_map_f, &lines);
}
