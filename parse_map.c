/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:07:20 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/22 18:41:18 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static t_bool	init_parse(t_parse *parse, t_str file, t_cubed *cubed)
{
	parse->cubed = cubed;
	parse->is_map = FALSE;
	parse->map_lines.n = 0;
	parse->map_lines.strs = NULL;
	parse->has_n = FALSE;
	parse->has_e = FALSE;
	parse->has_s = FALSE;
	parse->has_w = FALSE;
	parse->has_f = FALSE;
	parse->has_c = FALSE;
	parse->cubed->tex_n = NULL;
	parse->cubed->tex_e = NULL;
	parse->cubed->tex_s = NULL;
	parse->cubed->tex_w = NULL;
	parse->fd = open(file, O_RDONLY);
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

static void	free_parse(t_parse *parse)
{
	free(parse->cubed->tex_n);
	free(parse->cubed->tex_e);
	free(parse->cubed->tex_s);
	free(parse->cubed->tex_w);
	strl_free(&(parse->map_lines));
	close(parse->fd);
}

t_bool	parse_map(t_str file, t_cubed *cubed)
{
	t_parse	parse;

	if (!str_ext(file, FILE_EXTENSION))
		return (print_error("File extension not valid"), FALSE);
	if (!init_parse(&parse, file, cubed))
		return (FALSE);
	while (1)
	{
		parse.line = get_line(parse.fd);
		if (parse.line == NULL)
			break ;
		if (!parse_line(&parse))
			return (free(parse.line), free_parse(&parse), FALSE);
		free(parse.line);
	}
	if (!parse.has_n || !parse.has_e || !parse.has_s || !parse.has_w)
		return (print_error("Missing texture"), free_parse(&parse), FALSE);
	if (!parse.has_f || !parse.has_c)
		return (print_error("Missing color"), free_parse(&parse), FALSE);
	if (!process_map(&(cubed->map), &(parse.map_lines)))
		return (free_parse(&parse), FALSE);
	if (!validate_map(cubed))
		return (map_free(&(cubed->map)), free_parse(&parse), FALSE);
	return (strl_free(&(parse.map_lines)), close(parse.fd), TRUE);
}
