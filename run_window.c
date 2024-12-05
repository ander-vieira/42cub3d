/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:08:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 13:07:43 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	init_empty_map(t_map *map)
{
	t_lvec	pos;

	pos.x = 0;
	while (pos.x < map->w)
	{
		pos.y = 0;
		while (pos.y < map->h)
		{
			if (pos.x == 0 || pos.y == 0
				|| pos.x == map->w - 1 || pos.y == map->h - 1)
				map_set(map, pos, '1');
			else
				map_set(map, pos, '0');
			pos.y++;
		}
		pos.x++;
	}
}

//TODO remove hardcoded stuff
static void	runwn_init(t_run *r, t_cubed *cubed)
{
	r->cub = cubed;
	r->cub->color_c = 0x003a75c3;
	r->cub->color_f = 0x00f9dd17;
	r->cub->pos = dvec_new(1.5, 2.5);
	r->cub->dir = dvec_new(1, 0);
	map_init(&(r->cub->map), lvec_new(5, 5));
	init_empty_map(&(r->cub->map));
	map_set(&(r->cub->map), lvec_new(2, 2), '1');
	map_print(&(r->cub->map));
	r->mlx = mlx_init();
	r->scr = img_new(r->mlx, lvec_new(WIN_W, WIN_H));
	r->win = mlx_new_window(r->mlx, WIN_W, WIN_H, "HOLA MUNDO");
}

void	end_program(t_run *r)
{
	map_free(&(r->cub->map));
	img_free(r->mlx, r->scr);
	exit(EXIT_SUCCESS);
}

void	run_window(t_cubed *cubed)
{
	t_run	r;

	runwn_init(&r, cubed);
	mlx_loop_hook(r.mlx, &handler_loop, &r);
	mlx_hook(r.win, EVT_KEYDN, 0x1, (void *)&handler_keydn, &r);
	mlx_hook(r.win, EVT_DSTRY, 0, (void *)&handler_dstry, &r);
	mlx_loop(r.mlx);
}
