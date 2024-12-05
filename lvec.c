/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:05:29 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 13:08:47 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_lvec	lvec_new(t_uint x, t_uint y)
{
	t_lvec	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_lvec	lvec_add(t_lvec v1, t_lvec v2)
{
	t_lvec	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	return (v);
}
