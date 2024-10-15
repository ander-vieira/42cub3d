/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:08:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/15 18:50:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_window.h"

//TODO everything
void	run_window(t_cubed *cubed)
{
	t_runwn	runwn;

	runwn.cubed = cubed;
	runwn.cubed->color_c = 0x00FF0000;
	runwn.cubed->color_f = 0x0000FF00;
	runwn.mlx = mlx_init();
	runwn.win = mlx_new_window(runwn.mlx, WIN_W, WIN_H, "HOLA MUNDO");
	mlx_loop_hook(runwn.mlx, &handler_loop, &runwn);
	mlx_hook(runwn.win, EVT_KEYDN, 0x1, (void *)&handler_keydn, &runwn);
	mlx_hook(runwn.win, EVT_DSTRY, 0, (void *)&handler_dstry, &runwn);
	mlx_loop(runwn.mlx);
}
