/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <ahiguera@student.42urduliz.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:07:20 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/04 19:48:19 by alex             ###   ########.fr       */
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

void	init_textures(t_cubed *cubed)
{
	cubed->tex_n = NULL;
	cubed->tex_e = NULL;
	cubed->tex_s = NULL;
	cubed->tex_w = NULL;
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

t_bool	parse_map(t_str file, t_cubed *cubed)
{
	t_fd	fd;
	t_str	line;

	if (!check_file_extension(file, ".cub"))
		return (print_error("File not valid"), FALSE);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error(NULL), FALSE);
	init_textures(cubed);

	while ((line = get_line(fd)) != NULL)
	{
		if (parse_texture_property(line, cubed))
		{
			if (!parse_texture_property(line, cubed))
				printf("Error: Incorrect texture\n");
			else
				printf("TOKEN: %s", line);
		}
		free(line);
	}
	close(fd);
	if (!cubed->tex_n || !cubed->tex_e || !cubed->tex_s || !cubed->tex_w)
		return (print_error("Missing texture property"), FALSE);

	return (TRUE);
}
