/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:08:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 10:13:06 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	init_empty_map(t_map *map)
{
	t_uint	x;
	t_uint	y;

	x = 0;
	while (x < map->w)
	{
		y = 0;
		while (y < map->h)
		{
			if (x == 0 || y == 0 || x == map->w - 1 || y == map->h - 1)
				map_set(map, x, y, '1');
			else
				map_set(map, x, y, '0');
			y++;
		}
		x++;
	}
}

//TODO remove hardcoded stuff
static void	runwn_init(t_runwn *runwn, t_cubed *cubed)
{
	runwn->cubed = cubed;
	runwn->cubed->color_c = 0x003a75c3;
	runwn->cubed->color_f = 0x00f9dd17;
	runwn->cubed->pos = vec2_init(2.5, 2.5);
	runwn->cubed->dir = vec2_init(1, 0);
	map_init(&(runwn->cubed->map), 5, 5);
	init_empty_map(&(runwn->cubed->map));
	map_set(&(runwn->cubed->map), 1, 1, '1');
	map_print(&(runwn->cubed->map));
	runwn->mlx = mlx_init();
	runwn->scr = img_new(runwn->mlx, ivec2_new(WIN_W, WIN_H));
	runwn->win = mlx_new_window(runwn->mlx, WIN_W, WIN_H, "HOLA MUNDO");
}

void	end_program(t_runwn *runwn)
{
	map_free(&(runwn->cubed->map));
	img_free(runwn->mlx, runwn->scr);
	exit(EXIT_SUCCESS);
}

void	run_window(t_cubed *cubed)
{
	t_runwn	runwn;

	runwn_init(&runwn, cubed);
	mlx_loop_hook(runwn.mlx, &handler_loop, &runwn);
	mlx_hook(runwn.win, EVT_KEYDN, 0x1, (void *)&handler_keydn, &runwn);
	mlx_hook(runwn.win, EVT_DSTRY, 0, (void *)&handler_dstry, &runwn);
	mlx_loop(runwn.mlx);
}
