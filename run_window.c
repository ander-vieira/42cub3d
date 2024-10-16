/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:08:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/14 23:16:07 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_window.h"

//TODO everything
void	run_window(t_cubed *cubed)
{
	t_runwn	runwn;

	runwn.cubed = cubed;
	runwn.mlx = mlx_init();
	runwn.win = mlx_new_window(runwn.mlx, 800, 600, "HOLA MUNDO");
	mlx_loop_hook(runwn.mlx, &handler_loop, &runwn);
	mlx_hook(runwn.win, EVT_KEYDN, 0x1, (void *)&handler_keydn, &runwn);
	mlx_hook(runwn.win, EVT_DSTRY, 0, (void *)&handler_dstry, &runwn);
	mlx_loop(runwn.mlx);
}
