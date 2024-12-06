/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:45:02 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/06 16:20:10 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	rotate_mouse(t_run *r)
{
	int		x;
	int		y;
	double	angle;

	if (r->mus.focused)
	{
		mlx_mouse_get_pos(r->mlx, r->win, &x, &y);
		angle = MOUSE_SENS * (x - r->mus.x);
		r->dir = dvec_rot(r->dir, angle);
		mlx_mouse_move(r->mlx, r->win, WIN_W / 2, WIN_H / 2);
	}
}

int	handler_focusin(t_run *r)
{
	r->mus.x = WIN_W / 2;
	mlx_mouse_get_pos(r->mlx, r->win, &(r->mus.prev_x), &(r->mus.prev_y));
	mlx_mouse_move(r->mlx, r->win, WIN_W / 2, WIN_H / 2);
	r->mus.focused = TRUE;
	return (0);
}

int	handler_focusout(t_run *r)
{
	r->mus.focused = FALSE;
	mlx_mouse_move(r->mlx, r->win, r->mus.prev_x, r->mus.prev_y);
	return (0);
}
