/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:55:46 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/22 18:34:53 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static t_lvec	map_dimensions(t_strl *lines)
{
	t_lvec	dim;
	size_t	i;
	long	line_len;

	dim.y = lines->n;
	dim.x = 0;
	i = 0;
	while (i < lines->n)
	{
		line_len = 0;
		while (lines->strs[i][line_len] != '\0'
			&& lines->strs[i][line_len] != '\n')
			line_len++;
		if (line_len > dim.x)
			dim.x = line_len;
		i++;
	}
	return (dim);
}

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

t_bool	process_map(t_map *map, t_strl *lines)
{
	if (!map_init(map, map_dimensions(lines)))
		return (FALSE);
	map_foreach(map, &process_map_f, lines);
	return (TRUE);
}
