/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:58:27 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 21:24:29 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	fill_background(t_run *r, t_color color, t_lvec pos, t_lvec dim)
{
	t_cnv	cnv;
	t_lvec	v;

	cnv = img_cnv(r->scr);
	v.x = 0;
	while (v.x < dim.x)
	{
		v.y = 0;
		while (v.y < dim.y)
		{
			*(img_px(cnv, lvec_add(pos, v))) = color;
			v.y++;
		}
		v.x++;
	}
}

static void	draw_column(t_run *r, long x, t_castc c)
{
	t_cnv	cnv_scr;
	t_cnv	cnv_tex;
	long	y;
	long	tex_y;
	long	scr_y;

	cnv_scr = img_cnv(r->scr);
	if (c.side == SIDE_N)
		cnv_tex = img_cnv(r->img_n);
	else if (c.side == SIDE_E)
		cnv_tex = img_cnv(r->img_e);
	else if (c.side == SIDE_S)
		cnv_tex = img_cnv(r->img_s);
	else if (c.side == SIDE_W)
		cnv_tex = img_cnv(r->img_w);
	y = 0;
	while (y < c.h)
	{
		scr_y = y + (WIN_H - c.h) / 2;
		tex_y = y * TEX_H / c.h;
		if (scr_y >= 0 && scr_y < WIN_H)
			*(img_px(cnv_scr, lvec_new(x, y + (WIN_H - c.h) / 2)))
				= *(img_px(cnv_tex, lvec_new(c.tex_x, tex_y)));
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
	mlx_put_image_to_window(r->mlx, r->win, r->scr, 0, 0);
}

int	handler_loop(t_run *r)
{
	draw_view(r);
	return (0);
}
