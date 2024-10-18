/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:58:27 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/16 13:19:57 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_window.h"

int	handler_loop(t_runwn *runwn)
{
	mlx_put_image_to_window(runwn->mlx, runwn->win, runwn->img_c, 0, 0);
	mlx_put_image_to_window(runwn->mlx, runwn->win, runwn->img_f, 0, WIN_H / 2);
	return (0);
}
