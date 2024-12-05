/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:07:20 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 16:34:56 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

//TODO move these functions to the appropriate place
size_t	ft_strlen(t_str str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

t_bool	ft_strcmp(t_str str1, t_str str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (FALSE);
		i++;
	}
	if (str1[i] != str2[i])
		return (FALSE);
	return (TRUE);	
}

t_bool	check_file_extension(t_str file)
{
	if (ft_strlen(file) > 4 && ft_strcmp(file + ft_strlen(file) - 4, ".cub"))
		return (TRUE);
	else
		return (FALSE);
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
	t_uint		columnas_temp;
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
	map->dim = lvec_new(0, 0);
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
				map->dim.y++;
				// Actualizamos columnas máximas
				if (columnas_temp > map->dim.x)
					map->dim.x = columnas_temp;
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
		map->dim.y++;
		if (columnas_temp > map->dim.x)
			map->dim.x = columnas_temp;
	}
	map->tiles = temp_tiles;
	close(fd);
	return (TRUE);
}
