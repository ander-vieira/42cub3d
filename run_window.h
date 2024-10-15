/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:51:47 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/15 18:44:33 by andeviei         ###   ########.fr       */
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

typedef struct s_imgdw
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_w;
	int		endian;
}	t_imgdw;

typedef struct s_runwn
{
	t_cubed	*cubed;
	void	*mlx;
	void	*win;
}	t_runwn;

int		handler_dstry(t_runwn *runwn);
int		handler_keydn(int keycode, t_runwn *runwn);
int		handler_loop(t_runwn *runwn);

/* ************************************************************************** */
/* Module main function                                                       */
/* ************************************************************************** */

void	run_window(t_cubed *cubed);

#endif
