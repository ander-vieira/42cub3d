/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:58:27 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/04 19:36:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

// static void	get_pos(t_runwn *runwn)
// {
// 	double	t_x;
// 	double	t_y;
// 	double	d_x;
// 	double	d_y;
// 	t_vec2	pos;
// 	t_vec2	dir;

// 	pos = runwn->cubed->pos;
// 	dir = runwn->cubed->dir;
// 	if (dir.x > 0)
// 	{
// 		d_x = 1 / dir.x;
// 		t_x = d_x * (1 - fmod(pos.x, 1.));
// 	}
// 	else if (dir.x < 0)
// 	{
// 		d_x = 1 / (-dir.x);
// 		t_x = d_x * fmod(pos.x, 1.);
// 	}
// 	if (dir.y > 0)
// 	{
// 		d_y = 1 / dir.y;
// 		t_y = d_y * (1 - fmod(pos.y, 1.));
// 	}
// 	else if (dir.y < 0)
// 	{
// 		d_y = 1 / (-dir.y);
// 		t_y = d_y * fmod(pos.y, 1.);
// 	}
// 	while (1)
// 	{
// 		if (dir.y == 0 || (dir.x != 0 && t_x < t_y))
// 		{
// 			t_y -= t_x;
// 			t_x = 1 / fabs(dir.x); 
// 		}
// 		else
// 		{
// 		}
// 	}
// }

static t_vec2	get_col_dir(t_runwn *r, t_uint x)
{
	double	slope;
	double	total;
	double	scale = 1;

	slope = scale * (2 * (double)x / WIN_W - 1);
	total = sqrt(slope*slope + 1);
	return (vec2_init(r->cubed->dir.x / total - r->cubed->dir.y * slope / total,
		r->cubed->dir.y / total + r->cubed->dir.x * slope / total));
}

#include <stdio.h>
static t_uint	get_height(t_runwn *runwn, t_uint x)
{
	t_vec2	dir;
	double	x0;
	double	dx;
	double	y0;
	double	dy;

	dir = get_col_dir(runwn, x);
	if (dir.x < 0)
		x0 = (floor(runwn->cubed->pos.x) - runwn->cubed->pos.x) / dir.x;
	else
		x0 = (ceil(runwn->cubed->pos.x) - runwn->cubed->pos.x) / dir.x;
	dx = 1 / fabs(dir.x);
	if (dir.y < 0)
		y0 = (floor(runwn->cubed->pos.y) - runwn->cubed->pos.y) / dir.y;
	else
		y0 = (ceil(runwn->cubed->pos.y) - runwn->cubed->pos.y) / dir.y;
	dy = 1 / fabs(dir.y);
	printf("CASTING RAY (%f, %f)\n", dir.x, dir.y);
	while (TRUE)
	{
		t_vec2 v1;
		t_ivec2 v2;
		if (y0 < x0)
		{
			v1.x = runwn->cubed->pos.x + y0 * dir.x;
			v1.y = runwn->cubed->pos.y + y0 * dir.y;
			if (dir.y > 0)
			{
				v2 = ivec2_new(floor(v1.x), round(v1.y));
			}
			else
			{
				v2 = ivec2_new(floor(v1.x), round(v1.y) - 1);
			}
			if (map_get(&(runwn->cubed->map), v2.x, v2.y) == '1')
			{
				printf("RAY COLLIDED WITH WALL AT POSITION (%f, %f) (%zu, %zu)\n", v1.x, v1.y, v2.x, v2.y);
				return (100 / y0);
			}
			// printf("RAY GOES THROUGH POSITION (%f, %f)\n", v1.x, v1.y);
			y0 += dy;
		}
		else
		{
			v1.x = runwn->cubed->pos.x + x0 * dir.x;
			v1.y = runwn->cubed->pos.y + x0 * dir.y;
			if (dir.x > 0)
			{
				v2 = ivec2_new(round(v1.x), floor(v1.y));
			}
			else
			{
				v2 = ivec2_new(round(v1.x) - 1, floor(v1.y));
			}
			if (map_get(&(runwn->cubed->map), v2.x, v2.y) == '1')
			{
				printf("RAY COLLIDED WITH WALL AT POSITION (%f, %f) (%zu, %zu)\n", v1.x, v1.y, v2.x, v2.y);
				return (100 / x0);
			}
			// printf("RAY GOES THROUGH POSITION (%f, %f)\n", v1.x, v1.y);
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
