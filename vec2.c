/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:21:39 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/16 12:28:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_vec2	vec2_init(double x, double y)
{
	t_vec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vec2	vec2_add(t_vec2 v1, t_vec2 v2)
{
	t_vec2	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	return (v);
}

t_vec2	vec2_sub(t_vec2 v1, t_vec2 v2)
{
	t_vec2	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	return (v);
}

double	vec2_scalar(t_vec2 v1, t_vec2 v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

t_vec2	vec2_inv(t_vec2 v1)
{
	t_vec2	v;

	v.x = -v1.x;
	v.y = -v1.y;
	return (v);
}

t_vec2	vec2_normal(t_vec2 v1)
{
	t_vec2	v;

	v.x = v1.y;
	v.y = -v1.x;
	return (v);
}
