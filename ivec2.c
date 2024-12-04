/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:05:29 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/04 16:07:12 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_ivec2 ivec2_new(t_uint x, t_uint y)
{
	t_ivec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_ivec2 ivec2_add(t_ivec2 v1, t_ivec2 v2)
{
	t_ivec2	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	return (v);
}