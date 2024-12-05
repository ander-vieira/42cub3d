/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_keydn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:29:47 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 10:11:11 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

#include <stdio.h>

int	handler_keydn(int keycode, t_runwn *runwn)
{
	t_dvec dir;

	if (keycode == KEY_ESC)
		end_program(runwn);
	else if (keycode == KEY_W)
	{
		runwn->cubed->pos.x += runwn->cubed->dir.x * 0.2;
		runwn->cubed->pos.y += runwn->cubed->dir.y * 0.2;
		printf("New position: %f %f\n", runwn->cubed->pos.x, runwn->cubed->pos.y);
	}
	else if (keycode == KEY_S)
	{
		runwn->cubed->pos.x -= runwn->cubed->dir.x * 0.2;
		runwn->cubed->pos.y -= runwn->cubed->dir.y * 0.2;
		printf("New position: %f %f\n", runwn->cubed->pos.x, runwn->cubed->pos.y);
	}
	else if (keycode == KEY_A)
	{
		runwn->cubed->pos.x += runwn->cubed->dir.y * 0.2;
		runwn->cubed->pos.y -= runwn->cubed->dir.x * 0.2;
		printf("New position: %f %f\n", runwn->cubed->pos.x, runwn->cubed->pos.y);
	}
	else if (keycode == KEY_D)
	{
		runwn->cubed->pos.x -= runwn->cubed->dir.y * 0.2;
		runwn->cubed->pos.y += runwn->cubed->dir.x * 0.2;
		printf("New position: %f %f\n", runwn->cubed->pos.x, runwn->cubed->pos.y);
	}
	else if (keycode == KEY_LEFT)
	{
		dir.x = runwn->cubed->dir.x * 0.98480775301 + runwn->cubed->dir.y * 0.17364817766;
		dir.y = runwn->cubed->dir.y * 0.98480775301 - runwn->cubed->dir.x * 0.17364817766;
		runwn->cubed->dir = dir;
		printf("New direction: %f %f\n", runwn->cubed->dir.x, runwn->cubed->dir.y);
	}
	else if (keycode == KEY_RIGHT)
	{
		dir.x = runwn->cubed->dir.x * 0.98480775301 - runwn->cubed->dir.y * 0.17364817766;
		dir.y = runwn->cubed->dir.y * 0.98480775301 + runwn->cubed->dir.x * 0.17364817766;
		runwn->cubed->dir = dir;
		printf("New direction: %f %f\n", runwn->cubed->dir.x, runwn->cubed->dir.y);
	}
	return (0);
}
