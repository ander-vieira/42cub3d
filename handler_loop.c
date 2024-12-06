/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:58:27 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/06 15:48:31 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	fill_background(t_run *r, t_color color, t_lvec pos, t_lvec dim)
{
	t_lvec	v;

	v.x = 0;
	while (v.x < dim.x)
	{
		v.y = 0;
		while (v.y < dim.y)
		{
			*(img_px(r->scr, lvec_add(pos, v))) = color;
			v.y++;
		}
		v.x++;
	}
}

static void	draw_column(t_run *r, long x, t_castc c)
{
	t_img	img;
	long	y;

	if (c.side == SIDE_N)
		img = r->img_n;
	else if (c.side == SIDE_E)
		img = r->img_e;
	else if (c.side == SIDE_S)
		img = r->img_s;
	else if (c.side == SIDE_W)
		img = r->img_w;
	y = 0;
	if (c.h >= WIN_H)
		y = (c.h - WIN_H) / 2;
	while (y < c.h && y < (c.h + WIN_H) / 2)
	{
		*(img_px(r->scr, lvec_new(x, y + (WIN_H - c.h) / 2)))
			= *(img_px(img, lvec_new(c.tex_x, y * TEX_H / c.h)));
		y++;
	}
}

static void	draw_view(t_run *r)
{
	long	x;
	t_castc	c;

	fill_background(r, r->cub->color_c, lvec_new(0, 0),
		lvec_new(WIN_W, WIN_H / 2));
	fill_background(r, r->cub->color_f, lvec_new(0, WIN_H / 2),
		lvec_new(WIN_W, WIN_H / 2));
	x = 0;
	while (x < WIN_W)
	{
		c = raycast(r, x);
		draw_column(r, x, c);
		x++;
	}
	mlx_put_image_to_window(r->mlx, r->win, r->scr.i, 0, 0);
}

int	handler_loop(t_run *r)
{
	rotate_mouse(r);
	draw_view(r);
	return (0);
}
