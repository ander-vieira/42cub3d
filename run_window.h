/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:51:47 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 13:48:07 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_WINDOW_H
# define RUN_WINDOW_H

# include <stdlib.h>

# include "mlx/mlx.h"

# include "typedefs.h"

# define WIN_W		800
# define WIN_H		600

# define EVT_KEYDN	2
# define EVT_DSTRY	17

# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

# define TEX_W		32
# define TEX_H		32

# define STEP_DIST	0.2
# define TURN_ANGLE	0.08726646259

typedef struct s_imgdw
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_w;
	int		endian;
}	t_imgdw;

typedef struct s_castd
{
	double	scale;
	t_lvec	tile;
	double	dist_x;
	double	delta_x;
	t_bool	n_x;
	double	dist_y;
	double	delta_y;
	t_bool	n_y;
}	t_castd;

typedef struct s_castr
{
	double	dist;
	t_lvec	tile;
}	t_castr;

typedef struct s_run
{
	t_cubed	*cub;
	void	*mlx;
	void	*win;
	void	*scr;
}	t_run;

void	*img_load(void *mlx, char *file);
void	*img_new(void *mlx, t_lvec dim);
void	img_free(void *mlx, void *img);
void	img_fill(void *img, t_uint color, t_lvec pos, t_lvec dim);
void	img_put(void *img1, void *img2, t_lvec pos, t_lvec dim);

int		handler_dstry(t_run *r);
int		handler_keydn(int keycode, t_run *r);
int		handler_loop(t_run *r);

void	end_program(t_run *r);

/* ************************************************************************** */
/* Module main function                                                       */
/* ************************************************************************** */

void	run_window(t_cubed *cubed);

#endif
