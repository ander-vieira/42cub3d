/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:58:27 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/15 18:50:23 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_window.h"

static void	*draw_rectangle(t_runwn *runwn, int color)
{
	t_imgdw	imgdw;
	size_t	i;
	size_t	j;

	imgdw.img = mlx_new_image(runwn->mlx, WIN_W, WIN_H / 2);
	imgdw.addr = mlx_get_data_addr(imgdw.img, &(imgdw.bpp),
			&(imgdw.line_w), &(imgdw.endian));
	i = 0;
	while (i < WIN_W)
	{
		j = 0;
		while (j < WIN_H / 2)
		{
			*((unsigned int *)(imgdw.addr
						+ (j * imgdw.line_w + i * imgdw.bpp / 8))) = color;
			j++;
		}
		i++;
	}
	return (imgdw.img);
}

static void	draw_background(t_runwn *runwn)
{
	void	*img;

	img = draw_rectangle(runwn, runwn->cubed->color_c);
	mlx_put_image_to_window(runwn->mlx, runwn->win, img, 0, 0);
	mlx_destroy_image(runwn->mlx, img);
	img = draw_rectangle(runwn, runwn->cubed->color_f);
	mlx_put_image_to_window(runwn->mlx, runwn->win, img, 0, WIN_H / 2);
	mlx_destroy_image(runwn->mlx, img);
}

int	handler_loop(t_runwn *runwn)
{
	(void)runwn;
	draw_background(runwn);
	return (0);
}
