/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:07:20 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/02 20:37:07 by andeviei         ###   ########.fr       */
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
