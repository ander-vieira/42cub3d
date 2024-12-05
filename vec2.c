/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:21:39 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 10:11:11 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_dvec	vec2_init(double x, double y)
{
	t_dvec	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_dvec	vec2_add(t_dvec v1, t_dvec v2)
{
	t_dvec	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	return (v);
}

t_dvec	vec2_sub(t_dvec v1, t_dvec v2)
{
	t_dvec	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	return (v);
}

double	vec2_scalar(t_dvec v1, t_dvec v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

t_dvec	vec2_inv(t_dvec v1)
{
	t_dvec	v;

	v.x = -v1.x;
	v.y = -v1.y;
	return (v);
}

t_dvec	vec2_normal(t_dvec v1)
{
	t_dvec	v;

	v.x = v1.y;
	v.y = -v1.x;
	return (v);
}
