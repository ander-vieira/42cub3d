/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:58:27 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 10:23:40 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static t_uint	get_height(t_run *r, t_uint x)
{
	t_dvec	dir;
	double	x0;
	double	dx;
	double	y0;
	double	dy;
	double	slope;
	double	total;
	t_lvec	tile;
	double	dist;

	slope = 2 * (double)x / WIN_W - 1;
	total = sqrt(slope*slope + 1);
	dir = dvec_new(r->cubed->dir.x / total - r->cubed->dir.y * slope / total,
		r->cubed->dir.y / total + r->cubed->dir.x * slope / total);
	if (dir.x < 0)
	{
		tile.x = floor(r->cubed->pos.x);
		x0 = (floor(r->cubed->pos.x) - r->cubed->pos.x) / dir.x;
		dx = -1 / dir.x;
	}
	else
	{
		tile.x = floor(r->cubed->pos.x);
		x0 = (ceil(r->cubed->pos.x) - r->cubed->pos.x) / dir.x;
		dx = 1 / dir.x;
	}
	if (dir.y < 0)
	{
		tile.y = floor(r->cubed->pos.y);
		y0 = (floor(r->cubed->pos.y) - r->cubed->pos.y) / dir.y;
		dy = -1 / dir.y;
	}
	else
	{
		tile.y = floor(r->cubed->pos.y);
		y0 = (ceil(r->cubed->pos.y) - r->cubed->pos.y) / dir.y;
		dy = 1 / dir.y;
	}
	while (TRUE)
	{
		if (y0 < x0)
		{
			if (dir.y > 0)
				tile.y += 1;
			else
				tile.y -= 1;
			dist = y0;
			y0 += dy;
		}
		else
		{
			if (dir.x > 0)
				tile.x += 1;
			else
				tile.x -= 1;
			dist = x0;
			x0 += dx;
		}
		if (tile.x < 0 || tile.x >= r->cubed->map.w || tile.y < 0 || tile.y >= r->cubed->map.h)
			return (0);
		else if (map_get(&(r->cubed->map), tile) == '1')
			return (round(100. * total / dist));
	}
}

static void	draw_view(t_run *r)
{
	t_lvec	col;

	img_fill(r->scr, r->cubed->color_c, lvec_new(0, 0), lvec_new(WIN_W, WIN_H / 2));
	img_fill(r->scr, r->cubed->color_f, lvec_new(0, WIN_H / 2), lvec_new(WIN_W, WIN_H / 2));
	col.x = 0;
	while (col.x < WIN_W)
	{
		col.y = get_height(r, col.x);
		if (col.y > WIN_H / 2)
			col.y = WIN_H / 2;
		img_fill(r->scr, 0x00000000, lvec_new(col.x, WIN_H / 2 - col.y), lvec_new(1, 2 * col.y));
		col.x++;
	}
	mlx_put_image_to_window(r->mlx, r->win, r->scr, 0, 0);
}

int	handler_loop(t_run *r)
{
	draw_view(r);
	return (0);
}
