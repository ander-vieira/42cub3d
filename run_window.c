/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:08:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/01 13:29:43 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

//TODO everything
void	run_window(t_cubed *cubed)
{
	void	*mlx;
	void	*win;

	(void)cubed;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "HOLA MUNDO");
	(void)win;
	// mlx_loop_hook(g_sl()->mlx, &draw_map, NULL);
	// mlx_hook(g_sl()->win, EVT_KEYDN, 0, (void *)&handle_key, NULL);
	// mlx_hook(g_sl()->win, EVT_DSTRY, 0, (void *)&close_window, NULL);
	mlx_loop(mlx);
}
