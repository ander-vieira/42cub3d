/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:08:54 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/18 17:45:51 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	load_images(t_run *r)
{
	r->scr = img_new(r->mlx, lvec_new(WIN_W, WIN_H));
	r->img_n = img_load(r->mlx, r->cub->tex_n);
	r->img_e = img_load(r->mlx, r->cub->tex_e);
	r->img_s = img_load(r->mlx, r->cub->tex_s);
	r->img_w = img_load(r->mlx, r->cub->tex_w);
	if (r->scr.i == NULL)
	{
		print_error("Could not create screen");
		end_program(r, EXIT_FAILURE);
	}
	if (r->img_n.i == NULL || r->img_e.i == NULL
		|| r->img_s.i == NULL || r->img_w.i == NULL)
	{
		print_error("Incorrect texture loadin image");
		end_program(r, EXIT_FAILURE);
	}
}

static void	runwn_init(t_run *r, t_cubed *cub)
{
	r->cub = cub;
	r->pos = dvec_new(r->cub->pos.x + 0.5, r->cub->pos.y + 0.5);
	r->dir = dvec_trn(dvec_new(0, -1), r->cub->face);
	r->mlx = mlx_init();
	load_images(r);
	r->win = mlx_new_window(r->mlx, WIN_W, WIN_H, WIN_TITLE);
}

void	end_program(t_run *r, int status)
{
	map_free(&(r->cub->map));
	img_free(r->mlx, &(r->scr));
	img_free(r->mlx, &(r->img_n));
	img_free(r->mlx, &(r->img_e));
	img_free(r->mlx, &(r->img_s));
	img_free(r->mlx, &(r->img_w));
	exit(status);
}

void	run_window(t_cubed *cub)
{
	t_run	r;

	runwn_init(&r, cub);
	mlx_mouse_hide(r.mlx, r.win);
	mlx_loop_hook(r.mlx, &handler_loop, &r);
	mlx_hook(r.win, EVT_KEYDN, MASK_KEY, (void *)&handler_keydn, &r);
	mlx_hook(r.win, EVT_DSTRY, 0, (void *)&handler_dstry, &r);
	mlx_hook(r.win, EVT_FCIN, MASK_FOCUS, (void *)&handler_focusin, &r);
	mlx_hook(r.win, EVT_FCOUT, MASK_FOCUS, (void *)&handler_focusout, &r);
	mlx_loop(r.mlx);
}
