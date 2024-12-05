/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_keydn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:29:47 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 21:29:57 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	handler_keydn(int keycode, t_run *r)
{
	t_dvec	*pos;
	t_dvec	*dir;

	pos = &(r->pos);
	dir = &(r->dir);
	if (keycode == KEY_ESC)
		end_program(r);
	else if (keycode == KEY_W)
		*pos = dvec_add(*pos, dvec_scl(*dir, STEP_DIST));
	else if (keycode == KEY_S)
		*pos = dvec_add(*pos, dvec_scl(*dir, -STEP_DIST));
	else if (keycode == KEY_A)
		*pos = dvec_add(*pos, dvec_nrm(dvec_scl(*dir, -STEP_DIST)));
	else if (keycode == KEY_D)
		*pos = dvec_add(*pos, dvec_nrm(dvec_scl(*dir, STEP_DIST)));
	else if (keycode == KEY_LEFT)
		*dir = dvec_rot(*dir, -TURN_ANGLE);
	else if (keycode == KEY_RIGHT)
		*dir = dvec_rot(*dir, TURN_ANGLE);
	return (0);
}
