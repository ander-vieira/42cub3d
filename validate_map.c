/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:34:12 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/21 13:05:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	set_player(t_valid *valid, t_lvec pos, char c)
{
	if (valid->has_player)
	{
		print_error("Duplicate player");
		valid->ok = FALSE;
	}
	valid->cubed->pos = pos;
	if (c == MAP_PLAYER_N)
		valid->cubed->face = FACE_F;
	else if (c == MAP_PLAYER_E)
		valid->cubed->face = FACE_R;
	else if (c == MAP_PLAYER_S)
		valid->cubed->face = FACE_B;
	else if (c == MAP_PLAYER_W)
		valid->cubed->face = FACE_L;
	valid->has_player = TRUE;
}

static void	validate_map_f(t_map *map, t_lvec pos, void *ptr)
{
	t_valid	*valid;
	char	c;

	valid = ptr;
	if (!valid->ok)
		return ;
	c = map_get(map, pos);
	if (c == MAP_PLAYER_N || c == MAP_PLAYER_E
		|| c == MAP_PLAYER_S || c == MAP_PLAYER_W)
	{
		set_player(valid, pos, c);
		map_set(map, pos, MAP_FLOOR);
	}
	else if (c != MAP_WALL && c != MAP_FLOOR)
	{
		print_error("Invalid character");
		valid->ok = FALSE;
	}
}

static t_bool	copy_map(t_map map, t_map *copy)
{
	t_lvec	pos;

	if (!map_init(copy, map.dim))
		return (FALSE);
	pos.y = 0;
	while (pos.y < map.dim.y)
	{
		pos.x = 0;
		while (pos.x < map.dim.x)
		{
			map_set(copy, pos, map_get(&map, pos));
			pos.x++;
		}
		pos.y++;
	}
	return (TRUE);
}

static t_bool	flood_fill(t_map *map, t_lvec pos)
{
	char	c;

	if (pos.x < 0 || pos.x >= map->dim.x || pos.y < 0 || pos.y >= map->dim.y)
		return (FALSE);
	c = map_get(map, pos);
	if (c == '1' || c == 'F')
		return (TRUE);
	map_set(map, pos, MAP_FLOOD);
	if (!flood_fill(map, lvec_new(pos.x + 1, pos.y)))
		return (FALSE);
	if (!flood_fill(map, lvec_new(pos.x - 1, pos.y)))
		return (FALSE);
	if (!flood_fill(map, lvec_new(pos.x, pos.y + 1)))
		return (FALSE);
	if (!flood_fill(map, lvec_new(pos.x, pos.y - 1)))
		return (FALSE);
	return (TRUE);
}

t_bool	validate_map(t_cubed *cubed)
{
	t_valid	valid;
	t_map	copy;

	valid.cubed = cubed;
	valid.ok = TRUE;
	valid.has_player = FALSE;
	map_foreach(&(cubed->map), &validate_map_f, &valid);
	if (!valid.has_player)
		return (print_error("Missing player"), FALSE);
	if (!valid.ok)
		return (FALSE);
	if (!copy_map(cubed->map, &copy))
		return (FALSE);
	if (!flood_fill(&copy, cubed->pos))
		return (print_error("Map is not closed"), map_free(&copy), FALSE);
	return (map_free(&copy), TRUE);
}
