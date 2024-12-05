/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:08:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 21:33:27 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	init_empty_map(t_map *map)
{
	t_lvec	pos;

	pos.x = 0;
	while (pos.x < map->dim.x)
	{
		pos.y = 0;
		while (pos.y < map->dim.y)
		{
			if (pos.x == 0 || pos.y == 0
				|| pos.x == map->dim.x - 1 || pos.y == map->dim.y - 1)
				map_set(map, pos, '1');
			else
				map_set(map, pos, '0');
			pos.y++;
		}
		pos.x++;
	}
}

static void	load_images(t_run *r)
{
	r->img_n = img_load(r->mlx, r->cub->tex_n);
	r->img_e = img_load(r->mlx, r->cub->tex_e);
	r->img_s = img_load(r->mlx, r->cub->tex_s);
	r->img_w = img_load(r->mlx, r->cub->tex_w);
}

//TODO remove hardcoded stuff
static void	hardcode(t_cubed *cub)
{
	cub->color_c = 0x003a75c3;
	cub->color_f = 0x00f9dd17;
	cub->tex_n = "textures/north.xpm";
	cub->tex_e = "textures/east.xpm";
	cub->tex_s = "textures/south.xpm";
	cub->tex_w = "textures/west.xpm";
	cub->pos = lvec_new(1, 1);
	cub->dir = lvec_new(0, -1);
	map_init(&(cub->map), lvec_new(4, 4));
	init_empty_map(&(cub->map));
	map_print(&(cub->map));
}

static void	runwn_init(t_run *r, t_cubed *cub)
{
	r->cub = cub;
	r->pos = dvec_new(r->cub->pos.x + 0.5, r->cub->pos.y + 0.5);
	r->dir = dvec_new(r->cub->dir.x, r->cub->dir.y);
	r->mlx = mlx_init();
	r->scr = img_new(r->mlx, lvec_new(WIN_W, WIN_H));
	load_images(r);
	r->win = mlx_new_window(r->mlx, WIN_W, WIN_H, "HOLA MUNDO");
}

void	end_program(t_run *r)
{
	map_free(&(r->cub->map));
	img_free(r->mlx, r->scr);
	img_free(r->mlx, r->img_n);
	exit(EXIT_SUCCESS);
}

void	run_window(t_cubed *cub)
{
	t_run	r;

	hardcode(cub);
	runwn_init(&r, cub);
	mlx_loop_hook(r.mlx, &handler_loop, &r);
	mlx_hook(r.win, EVT_KEYDN, 0x1, (void *)&handler_keydn, &r);
	mlx_hook(r.win, EVT_DSTRY, 0, (void *)&handler_dstry, &r);
	mlx_loop(r.mlx);
}
