/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:58:27 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 13:16:43 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static t_castd	raycast_init(t_dvec pos, t_dvec dir, t_uint x)
{
	t_castd	c;
	double	slope;
	t_dvec	ray_dir;

	slope = 2 * (double)x / WIN_W - 1;
	c.scale = sqrt(slope * slope + 1);
	ray_dir = dvec_new(dir.x / c.scale - dir.y * slope / c.scale,
			dir.y / c.scale + dir.x * slope / c.scale);
	c.tile = lvec_new(floor(pos.x), floor(pos.y));
	if (ray_dir.x < 0)
		c.dist_x = (floor(pos.x) - pos.x) / ray_dir.x;
	else
		c.dist_x = (ceil(pos.x) - pos.x) / ray_dir.x;
	c.delta_x = 1 / fabs(ray_dir.x);
	c.n_x = (ray_dir.x < 0);
	if (ray_dir.y < 0)
		c.dist_y = (floor(pos.y) - pos.y) / ray_dir.y;
	else
		c.dist_y = (ceil(pos.y) - pos.y) / ray_dir.y;
	c.delta_y = 1 / fabs(ray_dir.y);
	c.n_y = (ray_dir.y < 0);
	return (c);
}

static t_castr	raycast_next(t_castd *c)
{
	t_castr	r;

	if (c->dist_y < c->dist_x)
	{
		if (c->n_y)
			c->tile.y -= 1;
		else
			c->tile.y += 1;
		r.dist = c->dist_y;
		c->dist_y += c->delta_y;
	}
	else
	{
		if (c->n_x)
			c->tile.x -= 1;
		else
			c->tile.x += 1;
		r.dist = c->dist_x;
		c->dist_x += c->delta_x;
	}
	r.tile = c->tile;
	return (r);
}

static t_uint	get_height(t_run *r, t_uint x)
{
	t_castd	castd;
	t_castr	castr;

	castd = raycast_init(r->cub->pos, r->cub->dir, x);
	while (TRUE)
	{
		castr = raycast_next(&castd);
		if (!map_has(&(r->cub->map), castr.tile))
			return (0);
		else if (map_get(&(r->cub->map), castr.tile) == '1')
			return (round(100. * castd.scale / castr.dist));
	}
}

static void	draw_view(t_run *r)
{
	t_lvec	col;

	img_fill(r->scr, r->cub->color_c, lvec_new(0, 0),
		lvec_new(WIN_W, WIN_H / 2));
	img_fill(r->scr, r->cub->color_f, lvec_new(0, WIN_H / 2),
		lvec_new(WIN_W, WIN_H / 2));
	col.x = 0;
	while (col.x < WIN_W)
	{
		col.y = get_height(r, col.x);
		if (col.y > WIN_H / 2)
			col.y = WIN_H / 2;
		img_fill(r->scr, 0x00000000, lvec_new(col.x, WIN_H / 2 - col.y),
			lvec_new(1, 2 * col.y));
		col.x++;
	}
	mlx_put_image_to_window(r->mlx, r->win, r->scr, 0, 0);
}

int	handler_loop(t_run *r)
{
	draw_view(r);
	return (0);
}
