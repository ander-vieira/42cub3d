/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_keydn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:29:47 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/04 19:38:11 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

#include <stdio.h>

int	handler_keydn(int keycode, t_runwn *runwn)
{
	t_vec2 dir;

	if (keycode == KEY_ESC)
		end_program(runwn);
	else if (keycode == KEY_W)
	{
		printf("PRESSED W\n");
		runwn->cubed->pos.x += runwn->cubed->dir.x * 0.2;
		runwn->cubed->pos.y += runwn->cubed->dir.y * 0.2;
		printf("BBB %f %f\n", runwn->cubed->pos.x, runwn->cubed->pos.y);
	}
	else if (keycode == KEY_S)
	{
		printf("PRESSED S\n");
		runwn->cubed->pos.x -= runwn->cubed->dir.x * 0.2;
		runwn->cubed->pos.y -= runwn->cubed->dir.y * 0.2;
		printf("BBB %f %f\n", runwn->cubed->pos.x, runwn->cubed->pos.y);
	}
	else if (keycode == KEY_A)
		printf("PRESSED A\n");
	else if (keycode == KEY_D)
		printf("PRESSED D\n");
	else if (keycode == KEY_LEFT)
	{
		printf("PRESSED LEFT\n");
		dir.x = runwn->cubed->dir.x * 0.8 + runwn->cubed->dir.y * 0.6;
		dir.y = runwn->cubed->dir.y * 0.8 - runwn->cubed->dir.x * 0.6;
		runwn->cubed->dir = dir;
		printf("AAA %f %f\n", runwn->cubed->dir.x, runwn->cubed->dir.y);
	}
	else if (keycode == KEY_RIGHT)
	{
		printf("PRESSED RIGHT\n");
		dir.x = runwn->cubed->dir.x * 0.8 - runwn->cubed->dir.y * 0.6;
		dir.y = runwn->cubed->dir.x * 0.6 + runwn->cubed->dir.y * 0.8;
		runwn->cubed->dir = dir;
		printf("AAA %f %f\n", runwn->cubed->dir.x, runwn->cubed->dir.y);
	}
	return (0);
}
