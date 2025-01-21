/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:51:47 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/21 11:49:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_WINDOW_H
# define RUN_WINDOW_H

# include "mlx/mlx.h"

# include "typedefs.h"

# define WIN_TITLE	"APRUEBAME"
# define WIN_W		800
# define WIN_H		600

# define EVT_KEYDN	2
# define EVT_FCIN	9
# define EVT_FCOUT	10
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

# define MASK_KEY	0x00000001
# define MASK_FOCUS	0x00200000

# define TEX_W		32
# define TEX_H		32

# define WALL_SCALE	300

# define STEP_DIST	0.2				//Moving distance per keypress
# define TURN_COS	0.996194698093	//Turn angle cos (precalculated for speed)
# define TURN_SIN	0.08715574274	//Turn angle sin (precalculated for speed)

# define MOUSE_SENS	20				//Mouse sensitivity

# define MMAP_SIZE	150				//Minimap size
# define MMAP_BRDRS	5				//Minimap border size
# define MMAP_BRDRC	0x00333333		//Minimap border color
# define MMAP_FLOOR	0x00808080		//Minimap floor tile color
# define MMAP_WALL	0x00333333		//Minimap wall tile color
# define MMAP_PLAYR	0x00FF0000		//Minimap player color

typedef enum e_side
{
	SIDE_NONE,
	SIDE_N,
	SIDE_E,
	SIDE_S,
	SIDE_W
}	t_side;

typedef struct s_img
{
	void	*i;
	char	*a;
	int		bpp;
	int		line;
}	t_img;

typedef struct s_castd
{
	double	scale;
	t_lvec	tile;
	t_dvec	dir;
	double	dist_x;
	double	delta_x;
	t_bool	n_x;
	double	dist_y;
	double	delta_y;
	t_bool	n_y;
}	t_castd;

typedef struct s_castn
{
	t_bool	is_y;
	double	dist;
	t_lvec	tile;
}	t_castn;

typedef struct s_castc
{
	t_side	side;
	long	tex_x;
	long	h;
}	t_castc;

typedef struct s_mouse
{
	t_bool	focused;
	int		stored_x;
	int		prev_x;
	int		prev_y;
}	t_mouse;

typedef struct s_run
{
	t_cubed	*cub;
	t_dvec	pos;
	t_dvec	dir;
	void	*mlx;
	void	*win;
	t_img	scr;
	t_img	img_n;
	t_img	img_s;
	t_img	img_w;
	t_img	img_e;
	t_mouse	mus;
}	t_run;

t_img	img_load(void *mlx, char *file);
t_img	img_new(void *mlx, t_lvec dim);
void	img_free(void *mlx, t_img *img);
t_img	img_cnv(void *img);
t_color	*img_px(t_img cnv, t_lvec pos);

int		handler_dstry(t_run *r);
int		handler_focusin(t_run *r);
int		handler_focusout(t_run *r);
int		handler_keydn(int keycode, t_run *r);
int		handler_loop(t_run *r);

void	end_program(t_run *r, int status);

t_castd	raycast_init(t_dvec pos, t_dvec dir, double slope);
t_castn	raycast_next(t_castd *d);
t_castc	raycast(t_run *r, long x);

void	rotate_mouse(t_run *r);
void	draw_minimap(t_run *r);

/* ************************************************************************** */
/* Module main function                                                       */
/* ************************************************************************** */

void	run_window(t_cubed *cubed);

#endif
