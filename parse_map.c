/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:07:20 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/22 16:46:44 by andeviei         ###   ########.fr       */
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

static t_bool	init_parse(t_parse *parse, t_str file, t_cubed *cubed)
{
	parse->cubed = cubed;
	parse->is_map = FALSE;
	parse->map_lines.n = 0;
	parse->map_lines.strs = NULL;
	parse->fd = open(file, O_RDONLY);
	parse->has_n = FALSE;
	parse->has_e = FALSE;
	parse->has_s = FALSE;
	parse->has_w = FALSE;
	parse->has_f = FALSE;
	parse->has_c = FALSE;
	if (parse->fd == -1)
		return (print_error(NULL), FALSE);
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

static t_bool	parse_line(t_parse *parse)
{
	t_strl	tokens;

	if (!strl_split(&tokens, parse->line))
		return (FALSE);
	if (!parse->is_map && tokens.n == 0)
		;
	else if (!parse->is_map && tokens.n == 2 && is_texture(tokens.strs[0]))
	{
		if (!read_texture(parse, tokens.strs[0], tokens.strs[1]))
			return (strl_free(&tokens), FALSE);
	}
	else if (!parse->is_map && tokens.n == 2 && is_color(tokens.strs[0]))
	{
		if (!read_color(parse, tokens.strs[0], tokens.strs[1]))
			return (strl_free(&tokens), FALSE);
	}
	else if (!add_map_line(&(parse->map_lines), parse->line, &(parse->is_map)))
		return (strl_free(&tokens), FALSE);
	return (strl_free(&tokens), TRUE);
}

t_bool	parse_map(t_str file, t_cubed *cubed)
{
	t_parse	parse;

	if (!check_file_extension(file, FILE_EXTENSION))
		return (print_error("File extension not valid"), FALSE);
	if (!init_parse(&parse, file, cubed))
		return (FALSE);
	while (1)
	{
		parse.line = get_line(parse.fd);
		if (parse.line == NULL)
			break ;
		if (!parse_line(&parse))
			return (free(parse.line), close(parse.fd), FALSE);
		free(parse.line);
	}
	if (!parse.has_n || !parse.has_e || !parse.has_s || !parse.has_w)
		return (print_error("Missing texture"),
			strl_free(&(parse.map_lines)), close(parse.fd), FALSE);
	if (!parse.has_f || !parse.has_c)
		return (print_error("Missing color"),
			strl_free(&(parse.map_lines)), close(parse.fd), FALSE);
	if (!process_map(&(cubed->map), &(parse.map_lines)))
		return (close(parse.fd), FALSE);
	if (!validate_map(cubed))
		return (map_free(&(cubed->map)), close(parse.fd), FALSE);
	return (close(parse.fd), TRUE);
}
