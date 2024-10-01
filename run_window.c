/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:08:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/01 16:39:51 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

//TODO add to header
#define EVT_KEYDN	2
#define EVT_DSTRY	17
int	handle_keys(int keycode, void *p);

// static int	draw_map(void *p)
// {
// 	t_vec2	pos;

// 	(void)p;
// 	pos.y = 0;
// 	while (pos.y < g_sl()->map.d.y)
// 	{
// 		pos.x = 0;
// 		while (pos.x < g_sl()->map.d.x)
// 		{
// 			map_drawtile(g_sl()->map, pos);
// 			pos.x++;
// 		}
// 		pos.y++;
// 	}
// 	return (0);
// }

static int	close_window(void *p)
{
	(void)p;
	exit(EXIT_SUCCESS);
	return (0);
}

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
	mlx_hook(win, EVT_KEYDN, 0, (void *)&handle_keys, NULL);
	mlx_hook(win, EVT_DSTRY, 0, (void *)&close_window, NULL);
	mlx_loop(mlx);
}
