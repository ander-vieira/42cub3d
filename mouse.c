/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:45:02 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/21 12:06:31 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	rotate_mouse(t_run *r)
{
	int		x;
	int		y;

	if (r->mus.focused)
	{
		mlx_mouse_get_pos(r->mlx, r->win, &x, &y);
		r->mus.stored_x += x - WIN_W / 2;
		while (r->mus.stored_x <= -MOUSE_SENS)
		{
			r->dir = dvec_rot(r->dir, TRUE);
			r->mus.stored_x += 2 * MOUSE_SENS;
		}
		while (r->mus.stored_x >= MOUSE_SENS)
		{
			r->dir = dvec_rot(r->dir, FALSE);
			r->mus.stored_x -= 2 * MOUSE_SENS;
		}
		mlx_mouse_move(r->mlx, r->win, WIN_W / 2, WIN_H / 2);
	}
}

int	handler_focusin(t_run *r)
{
	if (!r->mus.focused)
	{
		r->mus.stored_x = 0;
		mlx_mouse_get_pos(r->mlx, r->win, &(r->mus.prev_x), &(r->mus.prev_y));
		mlx_mouse_move(r->mlx, r->win, WIN_W / 2, WIN_H / 2);
		r->mus.focused = TRUE;
	}
	return (0);
}

int	handler_focusout(t_run *r)
{
	r->mus.focused = FALSE;
	mlx_mouse_move(r->mlx, r->win, r->mus.prev_x, r->mus.prev_y);
	return (0);
}
