/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:51:47 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/14 23:10:36 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_WINDOW_H
# define RUN_WINDOW_H

# include <stdlib.h>

# include "mlx/mlx.h"

# include "typedefs.h"

# define EVT_KEYDN	2
# define EVT_DSTRY	17

# define KEY_ESC	53
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

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
