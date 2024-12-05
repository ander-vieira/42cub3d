/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:21:39 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 13:41:47 by andeviei         ###   ########.fr       */
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

t_dvec	dvec_nrm(t_dvec v)
{
	return (dvec_new(-v.y, v.x));
}

t_dvec	dvec_rot(t_dvec v, double angle)
{
	double	c;
	double	s;

	c = cos(angle);
	s = sin(angle);
	return (dvec_new(v.x * c - v.y * s, v.x * s + v.y * c));
}
