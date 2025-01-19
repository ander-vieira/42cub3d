/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:07:20 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/20 00:01:30 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static t_bool	check_file_extension(t_str file, t_str ext)
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

static t_bool	add_map_line(t_strl *lines, t_str line, t_bool *is_map)
{
	t_str	*new_strs;
	size_t	i;

	*is_map = TRUE;
	new_strs = (t_str *)malloc(sizeof(t_str) * (lines->n + 1));
	if (new_strs == NULL)
		return (print_error(NULL), FALSE);
	i = 0;
	while (i < lines->n)
	{
		new_strs[i] = lines->strs[i];
		i++;
	}
	new_strs[lines->n] = str_dup(line);
	free(lines->strs);
	lines->strs = new_strs;
	lines->n += 1;
	return (TRUE);
}

static t_lvec	map_dimensions(t_strl lines)
{
	t_lvec	dim;
	size_t	i;
	long	line_len;

	dim.y = lines.n;
	dim.x = 0;
	i = 0;
	while (i < lines.n)
	{
		line_len = 0;
		while (lines.strs[i][line_len] != '\0'
			&& lines.strs[i][line_len] != '\n')
			line_len++;
		if (line_len > dim.x)
			dim.x = line_len;
		i++;
	}
	return (dim);
}

//TODO finish splitting parse_map into two functions, free tokens
// static t_bool	parse_line()
// {
// 	t_strl	tokens;

// 	tokens = split_strs(parse.line);
// 	if (!parse.is_map && tokens.n == 0)
// 		;
// 	else if (!parse.is_map && tokens.n == 2 && is_texture(tokens.strs[0]))
// 		read_texture(cubed, tokens.strs[0], tokens.strs[1]);
// 	else if (!parse.is_map && tokens.n == 2 && is_color(tokens.strs[0]))
// 	{
// 		if (!read_color(cubed, tokens.strs[0], tokens.strs[1]))
// 			return (free(parse.line), close(parse.fd), FALSE);
// 	}
// 	else if (!add_map_line(&(parse.map_lines), line, &(parse.is_map)))
// 		return (free(parse.line), close(parse.fd), FALSE);
// }

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
		parse.line = get_line(parse.fd);
		if (parse.line == NULL)
			break ;
		tokens = split_strs(parse.line);
		if (!parse.is_map && tokens.n == 0)
			;
		else if (!parse.is_map && tokens.n == 2 && is_texture(tokens.strs[0]))
			read_texture(cubed, tokens.strs[0], tokens.strs[1]);
		else if (!parse.is_map && tokens.n == 2 && is_color(tokens.strs[0]))
		{
			if (!read_color(cubed, tokens.strs[0], tokens.strs[1]))
				return (free(parse.line), close(parse.fd), FALSE);
		}
		else if (!add_map_line(&(parse.map_lines), line, &(parse.is_map)))
			return (free(parse.line), close(parse.fd), FALSE);
		free(parse.line);
	}
	if (!map_init(&(cubed->map), map_dimensions(parse.map_lines)))
		return (FALSE);
	process_map(&(cubed->map), parse.map_lines);
	if (!validate_map(cubed))
		return (close(parse.fd), FALSE);
	return (close(parse.fd), TRUE);
}
