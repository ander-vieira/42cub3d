/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:58:27 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/04 15:21:25 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

// static void	get_pos(t_runwn *runwn)
// {
// 	double	t_x;
// 	double	t_y;
// 	double	d_x;
// 	double	d_y;
// 	t_vec2	pos;
// 	t_vec2	dir;

// 	pos = runwn->cubed->pos;
// 	dir = runwn->cubed->dir;
// 	if (dir.x > 0)
// 	{
// 		d_x = 1 / dir.x;
// 		t_x = d_x * (1 - fmod(pos.x, 1.));
// 	}
// 	else if (dir.x < 0)
// 	{
// 		d_x = 1 / (-dir.x);
// 		t_x = d_x * fmod(pos.x, 1.);
// 	}
// 	if (dir.y > 0)
// 	{
// 		d_y = 1 / dir.y;
// 		t_y = d_y * (1 - fmod(pos.y, 1.));
// 	}
// 	else if (dir.y < 0)
// 	{
// 		d_y = 1 / (-dir.y);
// 		t_y = d_y * fmod(pos.y, 1.);
// 	}
// 	while (1)
// 	{
// 		if (dir.y == 0 || (dir.x != 0 && t_x < t_y))
// 		{
// 			t_y -= t_x;
// 			t_x = 1 / fabs(dir.x); 
// 		}
// 		else
// 		{
			
// 		}
// 	}
// }

static void	draw_view(t_runwn *runwn)
{
	size_t	x;
	static void	*img;

	if (img == NULL)
		img = img_rect(runwn->mlx, 0x00000000, 5, 200);
	x = 0;
	while (x < WIN_W / 5)
	{
		mlx_put_image_to_window(runwn->mlx, runwn->win, img, 5 * x, WIN_H / 2 - 100);
		x++;
	}
	// img_free(runwn->mlx, img);
}

int	handler_loop(t_runwn *runwn)
{
	mlx_put_image_to_window(runwn->mlx, runwn->win, runwn->img_c, 0, 0);
	mlx_put_image_to_window(runwn->mlx, runwn->win, runwn->img_f, 0, WIN_H / 2);
	draw_view(runwn);
	return (0);
}
