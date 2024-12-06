/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_keydn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:29:47 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/06 13:25:34 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	attempt_move(t_run *r, t_face face)
{
	t_dvec	dir;
	t_castd	d;
	t_castn	n;
	double	dist;

	dir = dvec_trn(r->dir, face);
	d = raycast_init(r->pos, dir, 0);
	while (TRUE)
	{
		n = raycast_next(&d);
		if (n.dist >= STEP_DIST)
		{
			dist = STEP_DIST;
			break ;
		}
		else if (map_get(&(r->cub->map), n.tile) == '1')
		{
			if (n.is_y)
				dist = n.dist - 0.01 / fabs(dir.y);
			else
				dist = n.dist - 0.01 / fabs(dir.x);
			break ;
		}
	}
	r->pos = dvec_add(r->pos, dvec_scl(dir, dist));
}

// static void	attempt_move(t_run *r, t_face face)
// {
// 	r->pos = dvec_add(r->pos, dvec_scl(dvec_trn(r->dir, face), STEP_DIST));
// }

int	handler_keydn(int keycode, t_run *r)
{
	if (keycode == KEY_ESC)
		end_program(r, EXIT_SUCCESS);
	else if (keycode == KEY_W)
		attempt_move(r, FACE_F);
	else if (keycode == KEY_D)
		attempt_move(r, FACE_R);
	else if (keycode == KEY_S)
		attempt_move(r, FACE_B);
	else if (keycode == KEY_A)
		attempt_move(r, FACE_L);
	else if (keycode == KEY_LEFT)
		r->dir = dvec_rot(r->dir, -TURN_ANGLE);
	else if (keycode == KEY_RIGHT)
		r->dir = dvec_rot(r->dir, TURN_ANGLE);
	return (0);
}
