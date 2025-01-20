/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:37:47 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/21 00:47:59 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_bool	is_texture(t_str prefix)
{
	return (str_cmp(prefix, PREFIX_NORTH) || str_cmp(prefix, PREFIX_EAST)
		|| str_cmp(prefix, PREFIX_SOUTH) || str_cmp(prefix, PREFIX_WEST));
}

void	read_texture(t_cubed *cubed, t_str prefix, t_str value)
{
	if (str_cmp(prefix, PREFIX_NORTH))
		cubed->tex_n = str_dup(value);
	else if (str_cmp(prefix, PREFIX_EAST))
		cubed->tex_e = str_dup(value);
	else if (str_cmp(prefix, PREFIX_SOUTH))
		cubed->tex_s = str_dup(value);
	else if (str_cmp(prefix, PREFIX_WEST))
		cubed->tex_w = str_dup(value);
}
