/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <ahiguera@student.42urduliz.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:07:20 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/15 18:49:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include <stdio.h>

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

void	init_cubed(t_cubed *cubed)
{
	cubed->tex_n = NULL;
	cubed->tex_e = NULL;
	cubed->tex_s = NULL;
	cubed->tex_w = NULL;
	cubed->color_c = 0;
	cubed->color_f = 0;
	cubed->map.tiles = NULL;
	cubed->map.dim.x = 0;
	cubed->map.dim.y = 0;
}

static t_bool	parse_texture_property(t_str line, t_cubed *cubed)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		cubed->tex_n = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		cubed->tex_s = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		cubed->tex_w = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		cubed->tex_e = ft_strdup(line + 3);
	else
		return (FALSE);
	return (TRUE);
}

static t_bool	is_map_line(t_str line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	parse_map_line(t_str line, t_cubed *cubed)
{
	long	len;
	t_lvec	pos;

	len = str_len(line);
	if (cubed->map.dim.x == 0)
		cubed->map.dim.x = len;
	else if (cubed->map.dim.x != len)
		return (print_error("Map line length mismatch"), FALSE);
	pos.y = cubed->map.dim.y;
	cubed->map.dim.y++;
	if (!map_init(&cubed->map, cubed->map.dim))
		return (print_error("Map initialization failed"), FALSE);
	pos.x = 0;
	while (pos.x < len)
	{
		map_set(&cubed->map, pos, line[pos.x]);
		pos.x++;
	}
	return (TRUE);
}

t_bool	parse_map_lines(t_fd fd, t_cubed *cubed)
{
	t_str	line;
	t_bool	map_started;

	map_started = FALSE;
	while ((line = get_line(fd)) != NULL)
	{
		if (is_map_line(line))
		{
			map_started = TRUE;
			if (!parse_map_line(line, cubed))
			{
				free(line);
				return (print_error("Incorrect map"), FALSE);
			}
		}
		else if (map_started && !is_map_line(line))
		{
			free(line);
			return (print_error("Map not continuous"), FALSE);
		}
		free(line);
	}
	return (TRUE);
}

t_bool	parse_map(t_str file, t_cubed *cubed)
{
	t_fd	fd;
	t_str	line;

	if (!check_file_extension(file, ".cub"))
		return (print_error("File not valid"), FALSE);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error(NULL), FALSE);
	init_cubed(cubed);

	while ((line = get_line(fd)) != NULL)
	{
		if (parse_texture_property(line, cubed))
		{
			printf("TOKEN: %s\n", line);
		}
		else if (is_map_line(line))
		{
			if (!parse_map_lines(fd, cubed))
			{
				free(line);
				return (print_error("Incorrect map"), FALSE);
			}
			printf("MAP LINE: %s\n", line);
		}
		/* else if (ft_strncmp(line, "F ", 2) == 0)
		{
			cubed->color_f = ft_atoi_base(line + 2, 16);
			printf("FLOOR COLOR: %d\n", cubed->color_f);
		}
		else if (ft_strncmp(line, "C ", 2) == 0)
		{
			cubed->color_c = ft_atoi_base(line + 2, 16);
			printf("CEILING COLOR: %d\n", cubed->color_c);
		} */
		else
		{
			printf("error\n");
		}
		free(line);
	}
	close(fd);
	if (!cubed->tex_n || !cubed->tex_e || !cubed->tex_s || !cubed->tex_w)
		return (print_error("Missing texture property"), FALSE);

	return (TRUE);
}
