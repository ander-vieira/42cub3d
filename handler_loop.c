/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:58:27 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/04 23:41:12 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static t_uint	get_height(t_runwn *runwn, t_uint x)
{
	t_vec2	dir;
	double	x0;
	double	dx;
	double	y0;
	double	dy;
	double	slope;
	double	total;
	t_ivec2	tile;

	slope = 2 * (double)x / WIN_W - 1;
	total = sqrt(slope*slope + 1);
	dir = vec2_init(runwn->cubed->dir.x / total - runwn->cubed->dir.y * slope / total,
		runwn->cubed->dir.y / total + runwn->cubed->dir.x * slope / total);
	if (dir.x < 0)
	{
		tile.x = floor(runwn->cubed->pos.x);
		x0 = (floor(runwn->cubed->pos.x) - runwn->cubed->pos.x) / dir.x;
		dx = -1 / dir.x;
	}
	else
	{
		tile.x = floor(runwn->cubed->pos.x);
		x0 = (ceil(runwn->cubed->pos.x) - runwn->cubed->pos.x) / dir.x;
		dx = 1 / dir.x;
	}
	if (dir.y < 0)
	{
		tile.y = floor(runwn->cubed->pos.y);
		y0 = (floor(runwn->cubed->pos.y) - runwn->cubed->pos.y) / dir.y;
		dy = -1 / dir.y;
	}
	else
	{
		tile.y = floor(runwn->cubed->pos.y);
		y0 = (ceil(runwn->cubed->pos.y) - runwn->cubed->pos.y) / dir.y;
		dy = 1 / dir.y;
	}
	while (TRUE)
	{
		t_vec2 v1;
		if (y0 < x0)
		{
			if (dir.y > 0)
				tile.y += 1;
			else
				tile.y -= 1;
			v1.x = runwn->cubed->pos.x + y0 * dir.x;
			v1.y = runwn->cubed->pos.y + y0 * dir.y;
			if (map_get(&(runwn->cubed->map), tile.x, tile.y) == '1')
				return (round(100. * total / y0));
			y0 += dy;
		}
		else
		{
			if (dir.x > 0)
				tile.x += 1;
			else
				tile.x -= 1;
			v1.x = runwn->cubed->pos.x + x0 * dir.x;
			v1.y = runwn->cubed->pos.y + x0 * dir.y;
			if (map_get(&(runwn->cubed->map), tile.x, tile.y) == '1')
				return (round(100. * total / x0));
			x0 += dx;
		}
		if (v1.x < 0 || v1.x >= runwn->cubed->map.w || v1.y < 0 || v1.y >= runwn->cubed->map.h)
			return (0);
	}
}

static void	draw_view(t_runwn *runwn)
{
	t_ivec2	col;

	img_fill(runwn->scr, runwn->cubed->color_c, ivec2_new(0, 0), ivec2_new(WIN_W, WIN_H / 2));
	img_fill(runwn->scr, runwn->cubed->color_f, ivec2_new(0, WIN_H / 2), ivec2_new(WIN_W, WIN_H / 2));
	col.x = 0;
	while (col.x < WIN_W)
	{
		col.y = get_height(runwn, col.x);
		if (col.y > WIN_H / 2)
			col.y = WIN_H / 2;
		img_fill(runwn->scr, 0x00000000, ivec2_new(col.x, WIN_H / 2 - col.y), ivec2_new(1, 2 * col.y));
		col.x++;
	}
	mlx_put_image_to_window(runwn->mlx, runwn->win, runwn->scr, 0, 0);
}

int	handler_loop(t_runwn *runwn)
{
	draw_view(runwn);
	return (0);
}
