/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:07:20 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/16 20:44:45 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_bool	check_file_extension(t_str file, t_str ext)
{
	size_t	file_len;
	size_t	ext_len;
	size_t	i;

	file_len = str_len(file);
	ext_len = str_len(ext);
	if (file_len <= ext_len)
		return (FALSE);
	i = 0;
	while (i < ext_len)
	{
		if (file[file_len - ext_len + i] != ext[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	is_texture(t_str prefix)
{
	return (str_cmp(prefix, PREFIX_NORTH) || str_cmp(prefix, PREFIX_EAST)
		|| str_cmp(prefix, PREFIX_SOUTH) || str_cmp(prefix, PREFIX_WEST));
}

void	read_texture(t_cubed *cubed, t_str prefix, t_str value)
{
	if (str_cmp(prefix, PREFIX_NORTH))
		cubed->tex_n = value;
	else if (str_cmp(prefix, PREFIX_EAST))
		cubed->tex_e = value;
	else if (str_cmp(prefix, PREFIX_SOUTH))
		cubed->tex_s = value;
	else if (str_cmp(prefix, PREFIX_WEST))
		cubed->tex_w = value;
}

t_bool	parse_byte(t_str value, size_t *i, t_byte *byte)
{
	t_bool	empty;
	t_byte	digit;

	empty = TRUE;
	while (value[*i] >= '0' && value[*i] <= '9')
	{
		empty = FALSE;
		digit = value[*i] - '0';
		if (*byte > 25 || (*byte == 25 && digit > 5))
			return (print_error("TODO"), FALSE);
		*byte = (*byte) * 10 + digit;
		*i += 1;
	}
	if (empty)
		return (print_error("TODO"), FALSE);
	return (TRUE);
}

t_bool	parse_color(t_str value, t_color *color)
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

t_bool	is_color(t_str prefix)
{
	return (str_cmp(prefix, PREFIX_FLOOR) || str_cmp(prefix, PREFIX_CEILING));
}

t_bool	read_color(t_cubed *cubed, t_str prefix, t_str value)
{
	t_color	color;

	if (!parse_color(value, &color))
		return (FALSE);
	else if (str_cmp(prefix, PREFIX_FLOOR))
		cubed->color_f = color;
	else if (str_cmp(prefix, PREFIX_CEILING))
		cubed->color_c = color;
	return (TRUE);
}

t_bool	add_map_line(t_strl *lines, t_str line)
{
	t_str	*new_strs;
	size_t	i;

	new_strs = (t_str *)malloc(sizeof(t_str) * (lines->n + 1));
	if (new_strs == NULL)
		return (print_error(NULL), FALSE);
	i = 0;
	while (i < lines->n)
	{
		new_strs[i] = lines->strs[i];
		i++;
	}
	new_strs[lines->n] = line;
	free(lines->strs);
	lines->strs = new_strs;
	lines->n += 1;
	return (TRUE);
}

//TODO XD
void	process_map(t_cubed *cubed, t_strl *lines)
{
	(void)cubed;
	(void)lines;
}

t_bool	parse_map(t_str file, t_cubed *cubed)
{
	t_parse	parse;
	t_str	line;
	t_strl	tokens;

	if (!check_file_extension(file, FILE_EXTENSION))
		return (print_error("File extension not valid"), FALSE);
	parse.fd = open(file, O_RDONLY);
	if (parse.fd == -1)
		return (print_error(NULL), FALSE);
	parse.is_map = FALSE;
	while (1)
	{
		line = get_line(parse.fd);
		if (line == NULL)
			break ;
		tokens = split_strs(line);
		if (!parse.is_map && tokens.n == 2 && is_texture(tokens.strs[0]))
			read_texture(cubed, tokens.strs[0], tokens.strs[1]);
		else if (!parse.is_map && tokens.n == 2 && is_color(tokens.strs[0])
			&& !read_color(cubed, tokens.strs[0], tokens.strs[1]))
			return (free(line), close(parse.fd), FALSE);
		else if (!add_map_line(&(parse.map_lines), line))
			return (free(line), close(parse.fd), FALSE);
		free(line);
	}
	process_map(cubed, &(parse.map_lines));
	map_print(&(cubed->map));
	return (close(parse.fd), TRUE);
}
