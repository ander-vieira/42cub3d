/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <ahiguera@student.42urduliz.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:07:20 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/05 04:20:08 by alex             ###   ########.fr       */
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
// TODO: no permitir texturas repetidas
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
/* 
t_bool	parse_map(t_str file, t_cubed *cubed)
{
	t_fd	fd;
	t_str	line;

	(void)cubed;
	if (!check_file_extension(file, ".cub"))
		return (FALSE);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error(NULL), FALSE);
	while (1)
	{
		
		// if (la linea es una propiedad)
		// 	leer la propiedad
		// 	si es duplicada
		// 		error
		// if (la linea no es una propiedad | estamos en modo mapa)
		// 	cambiar a modo mapa
		// 	comprobar que estan todas las propiedades
		// 	leer la linea del mapa
		line = get_line(fd);
		if (line == NULL)
			break ;
		printf("LINE\n");
		t_strl	strl = split_strs(line);
		size_t	i = 0;
		while (i < strl.n)
		{
			printf("TOKEN: %s\n", strl.strs[i]);
			i++;
		}
		free(line);
	}
	close(fd);
	// parsear las lineas de mapa al formato correcto y sacar las dimensiones
	// sacar la posicion del jugador y cambiar casillas a 0 y 1
	return (TRUE);
}

 */

static t_bool	parse_color_property(t_str line, t_cubed *cubed)
{
	t_str	colors;
	t_color	color_hex;
	t_strl	color_tokens;
	int		rgb[3];
	int		i;


	if (ft_strncmp(line, "F ", 2) == 0)
		colors = line + 2;
	else if (ft_strncmp(line, "C ", 2) == 0)
		colors = line + 2;
	else
		return (FALSE);
	color_tokens = split_strs(colors);
	if (color_tokens.n != 3)
		return (print_error("Invalid color format"), FALSE);
	i = 0;
	while (i < 3)
	{
		rgb[i] = ft_atoi(color_tokens.strs[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (print_error("Color value out of range"), FALSE);
		i++;
	}
	color_hex = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	if (line[0] == 'F')
		cubed->color_f = color_hex;
	else if (line[0] == 'C')
		cubed->color_c = color_hex;
	//printf("COLOR: %0x %0x\n", cubed->color_f, cubed->color_c);
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
			if (!parse_texture_property(line, cubed))
			{
				free(line);
				return (print_error("Incorrect texture"), FALSE);
			}
			else
				printf("TEXTURES: %s", line);
		}
		else if (parse_color_property(line, cubed))
		{
			if (!parse_color_property(line, cubed))
			{
				free(line);
				return (print_error("Incorrect color"), FALSE);
			}
			else
				printf("Colors: %s", line);
		}
		free(line);
	}
	close(fd);
	return (TRUE);
}
