/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_keydn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:29:47 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 10:19:09 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

#include <stdio.h>

int	handler_keydn(int keycode, t_run *r)
{
	t_dvec dir;

	if (keycode == KEY_ESC)
		end_program(r);
	else if (keycode == KEY_W)
	{
		r->cubed->pos.x += r->cubed->dir.x * 0.2;
		r->cubed->pos.y += r->cubed->dir.y * 0.2;
		printf("New position: %f %f\n", r->cubed->pos.x, r->cubed->pos.y);
	}
	else if (keycode == KEY_S)
	{
		r->cubed->pos.x -= r->cubed->dir.x * 0.2;
		r->cubed->pos.y -= r->cubed->dir.y * 0.2;
		printf("New position: %f %f\n", r->cubed->pos.x, r->cubed->pos.y);
	}
	else if (keycode == KEY_A)
	{
		r->cubed->pos.x += r->cubed->dir.y * 0.2;
		r->cubed->pos.y -= r->cubed->dir.x * 0.2;
		printf("New position: %f %f\n", r->cubed->pos.x, r->cubed->pos.y);
	}
	else if (keycode == KEY_D)
	{
		r->cubed->pos.x -= r->cubed->dir.y * 0.2;
		r->cubed->pos.y += r->cubed->dir.x * 0.2;
		printf("New position: %f %f\n", r->cubed->pos.x, r->cubed->pos.y);
	}
	else if (keycode == KEY_LEFT)
	{
		dir.x = r->cubed->dir.x * 0.98480775301 + r->cubed->dir.y * 0.17364817766;
		dir.y = r->cubed->dir.y * 0.98480775301 - r->cubed->dir.x * 0.17364817766;
		r->cubed->dir = dir;
		printf("New direction: %f %f\n", r->cubed->dir.x, r->cubed->dir.y);
	}
	else if (keycode == KEY_RIGHT)
	{
		dir.x = r->cubed->dir.x * 0.98480775301 - r->cubed->dir.y * 0.17364817766;
		dir.y = r->cubed->dir.y * 0.98480775301 + r->cubed->dir.x * 0.17364817766;
		r->cubed->dir = dir;
		printf("New direction: %f %f\n", r->cubed->dir.x, r->cubed->dir.y);
	}
	return (0);
}
