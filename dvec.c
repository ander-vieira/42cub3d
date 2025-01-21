/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:21:39 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/21 11:33:44 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_dvec	dvec_new(double x, double y)
{
	t_dvec	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_dvec	dvec_add(t_dvec v1, t_dvec v2)
{
	return (dvec_new(v1.x + v2.x, v1.y + v2.y));
}

t_dvec	dvec_scl(t_dvec v, double scale)
{
	return (dvec_new(v.x * scale, v.y * scale));
}

t_dvec	dvec_trn(t_dvec v, t_face face)
{
	if (face == FACE_F)
		return (v);
	else if (face == FACE_R)
		return (dvec_new(-v.y, v.x));
	else if (face == FACE_B)
		return (dvec_new(-v.x, -v.y));
	else
		return (dvec_new(v.y, -v.x));
}

t_dvec	dvec_rot(t_dvec v, t_bool reverse)
{
	if (reverse)
		return (dvec_new(v.x * TURN_COS + v.y * TURN_SIN,
			v.y * TURN_COS - v.x * TURN_SIN));
	else
		return (dvec_new(v.x * TURN_COS - v.y * TURN_SIN,
			v.y * TURN_COS + v.x * TURN_SIN));
}
