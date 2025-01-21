/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:37:57 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/21 13:01:44 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_bool	is_color(t_str prefix)
{
	return (str_cmp(prefix, PREFIX_FLOOR) || str_cmp(prefix, PREFIX_CEILING));
}

static t_bool	parse_byte(t_str value, size_t *i, t_byte *byte)
{
	t_bool	empty;
	t_byte	digit;

	empty = TRUE;
	while (value[*i] >= '0' && value[*i] <= '9')
	{
		empty = FALSE;
		digit = value[*i] - '0';
		if (*byte > 25 || (*byte == 25 && digit > 5))
			return (FALSE);
		*byte = (*byte) * 10 + digit;
		*i += 1;
	}
	if (empty)
		return (FALSE);
	return (TRUE);
}

static t_bool	parse_color(t_str value, t_color *color)
{
	size_t	i;

	*color = 0;
	i = 0;
	if (!parse_byte(value, &i, (t_byte *)color + 2))
		return (FALSE);
	if (value[i++] != ',')
		return (FALSE);
	if (!parse_byte(value, &i, (t_byte *)color + 1))
		return (FALSE);
	if (value[i++] != ',')
		return (FALSE);
	if (!parse_byte(value, &i, (t_byte *)color))
		return (FALSE);
	if (value[i++] != '\0')
		return (FALSE);
	return (TRUE);
}

static t_bool	read_color_type(t_color value, t_color *color, t_bool *has)
{
	if (*has)
		return (print_error("Duplicate color"), FALSE);
	*color = value;
	*has = TRUE;
	return (TRUE);
}

t_bool	read_color(t_parse *parse, t_str prefix, t_str value)
{
	t_color	color;

	if (!parse_color(value, &color))
		return (print_error("Invalid color"), FALSE);
	else if (str_cmp(prefix, PREFIX_FLOOR))
		return (read_color_type(color,
				&(parse->cubed->color_f), &(parse->has_f)));
	else if (str_cmp(prefix, PREFIX_CEILING))
		return (read_color_type(color,
				&(parse->cubed->color_c), &(parse->has_c)));
	return (FALSE);
}
