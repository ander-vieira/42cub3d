/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_keydn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:29:47 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/15 18:31:35 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

#include <stdio.h>

int	handler_keydn(int keycode, t_runwn *runwn)
{
	(void)runwn;
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == KEY_W)
		printf("PRESSED W\n");
	else if (keycode == KEY_S)
		printf("PRESSED S\n");
	else if (keycode == KEY_A)
		printf("PRESSED A\n");
	else if (keycode == KEY_D)
		printf("PRESSED D\n");
	else if (keycode == KEY_LEFT)
		printf("PRESSED LEFT\n");
	else if (keycode == KEY_RIGHT)
		printf("PRESSED RIGHT\n");
	return (0);
}
