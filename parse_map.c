/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:07:20 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/15 16:20:23 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_bool	check_file_extension(t_str file)
{
	if (ft_strlen(file) > 4 && \
		(ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4) == 0))
		return(TRUE);
	else
		return(FALSE);
}

//TODO everything
/* t_bool	parse_map(t_str file, t_cubed *cubed)
{
	t_map	*map;
	t_fd	fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (file < 0)
	{
		print_error("Map failed");
		return (FALSE);
	}
	map = get_next_line(fd);
	
	return (TRUE);
} */

t_bool	parse_map(t_str file, t_cubed *cubed)
{
	t_map		*map;
	t_fd		fd;
	char		buffer[1024];
	int			bytes_leidos;
	int			total_caracteres;
	int			columnas_temp;
	int			i;
	char 		*temp_tiles;

	total_caracteres = 0;
	columnas_temp = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error("Error al abrir el archivo");
		return (FALSE);
	}
	map = &cubed->map;
	map->x = 0;
	map->y = 0;
	map->tiles = NULL;
	temp_tiles = NULL;
	// Leer y procesar el archivo en una sola pasada
	while ((bytes_leidos = read(fd, buffer, sizeof(buffer))) > 0)
	{
		i = 0;
		while (i < bytes_leidos)
		{
			if (buffer[i] == '\n')
			{
				map->y++;
				// Actualizamos columnas máximas
				if (columnas_temp > map->x)
					map->x = columnas_temp;
				columnas_temp = 0;
			}
			else
			{
				columnas_temp++;
				// Reservar memoria dinámica y agregar al buffer temporal
				temp_tiles = realloc(temp_tiles, total_caracteres + 1);
				if (!temp_tiles)
				{
					print_error("memory allocation");
					close(fd);
					return (FALSE);
				}
				// Añadir el carácter
				temp_tiles[total_caracteres++] = buffer[i];
			}
			i++;
		}
	}
    // Maneja el caso de que no haya nueva linea al final
	if (columnas_temp > 0)
	{
		map->y++;
		if (columnas_temp > map->x)
			map->x = columnas_temp;
	}
	map->tiles = temp_tiles;
	close(fd);
	return (TRUE);
}
