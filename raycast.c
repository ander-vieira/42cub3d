/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:40:22 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 18:50:25 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static t_castd	raycast_init(t_dvec pos, t_dvec dir, long x)
{
	t_castd	d;
	double	slope;

	slope = 2 * (double)x / WIN_W - 1;
	d.scale = sqrt(slope * slope + 1);
	d.dir = dvec_new(dir.x / d.scale - dir.y * slope / d.scale,
			dir.y / d.scale + dir.x * slope / d.scale);
	d.tile = lvec_new(floor(pos.x), floor(pos.y));
	if (d.dir.x < 0)
		d.dist_x = (floor(pos.x) - pos.x) / d.dir.x;
	else
		d.dist_x = (ceil(pos.x) - pos.x) / d.dir.x;
	d.delta_x = 1 / fabs(d.dir.x);
	d.n_x = (d.dir.x < 0);
	if (d.dir.y < 0)
		d.dist_y = (floor(pos.y) - pos.y) / d.dir.y;
	else
		d.dist_y = (ceil(pos.y) - pos.y) / d.dir.y;
	d.delta_y = 1 / fabs(d.dir.y);
	d.n_y = (d.dir.y < 0);
	return (d);
}

static t_castn	raycast_next(t_castd *d)
{
	t_castn	n;

	n.is_y = (d->dist_y <= d->dist_x);
	if (n.is_y)
	{
		if (d->n_y)
			d->tile.y -= 1;
		else
			d->tile.y += 1;
		n.dist = d->dist_y;
		d->dist_y += d->delta_y;
	}
	else
	{
		if (d->n_x)
			d->tile.x -= 1;
		else
			d->tile.x += 1;
		n.dist = d->dist_x;
		d->dist_x += d->delta_x;
	}
	n.tile = d->tile;
	return (n);
}

static t_castc	raycast_cempty(void)
{
	t_castc	c;

	c.side = SIDE_NONE;
	c.h = 0;
	return (c);
}

static t_castc	raycast_cget(t_run *r, t_castd d, t_castn n)
{
	t_castc	c;
	double	offset;

	if (n.is_y)
	{
		if (d.dir.y < 0)
			c.side = SIDE_N;
		else
			c.side = SIDE_S;
		offset = r->cub->pos.x + n.dist * d.dir.x;
	}
	else
	{
		if (d.dir.x < 0)
			c.side = SIDE_W;
		else
			c.side = SIDE_E;
		offset = r->cub->pos.y + n.dist * d.dir.y;
	}
	c.h = round(300 * d.scale / n.dist);
	if (c.side == SIDE_S || c.side == SIDE_W)
		c.tex_x = floor(TEX_W * (ceil(offset) - offset));
	else
		c.tex_x = floor(TEX_W * (offset - floor(offset)));
	return (c);
}

t_castc	raycast(t_run *r, long x)
{
	t_castd	d;
	t_castn	n;

	d = raycast_init(r->cub->pos, r->cub->dir, x);
	while (TRUE)
	{
		n = raycast_next(&d);
		if ((d.n_x && n.tile.x < 0)
			|| (!d.n_x && n.tile.x >= r->cub->map.dim.x)
			|| (d.n_y && n.tile.y < 0)
			|| (!d.n_y && n.tile.y >= r->cub->map.dim.y))
			return (raycast_cempty());
		else if (map_get(&(r->cub->map), n.tile) == '1')
			return (raycast_cget(r, d, n));
	}
}
