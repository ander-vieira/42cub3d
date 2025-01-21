/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:37:47 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/21 12:58:37 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_bool	is_texture(t_str prefix)
{
	return (str_cmp(prefix, PREFIX_NORTH) || str_cmp(prefix, PREFIX_EAST)
		|| str_cmp(prefix, PREFIX_SOUTH) || str_cmp(prefix, PREFIX_WEST));
}

static t_bool	read_texture_type(t_str value, t_str *tex, t_bool *has)
{
	if (*has)
		return (print_error("Duplicate texture"), FALSE);
	*tex = str_dup(value);
	*has = TRUE;
	return (TRUE);
}

t_bool	read_texture(t_parse *parse, t_str prefix, t_str value)
{
	if (str_cmp(prefix, PREFIX_NORTH))
		return (read_texture_type(value,
				&(parse->cubed->tex_n), &(parse->has_n)));
	else if (str_cmp(prefix, PREFIX_EAST))
		return (read_texture_type(value,
				&(parse->cubed->tex_e), &(parse->has_e)));
	else if (str_cmp(prefix, PREFIX_SOUTH))
		return (read_texture_type(value,
				&(parse->cubed->tex_s), &(parse->has_s)));
	else if (str_cmp(prefix, PREFIX_WEST))
		return (read_texture_type(value,
				&(parse->cubed->tex_w), &(parse->has_w)));
	return (FALSE);
}
