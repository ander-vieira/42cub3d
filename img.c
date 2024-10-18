/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:35:06 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/16 13:12:37 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	*img_load(void *mlx, char *file)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(mlx, file, &w, &h);
	if (img == NULL)
		return (NULL);
	if (w != TEX_W || h != TEX_H)
		return (NULL);
	return (img);
}

void	*img_rect(void *mlx, int color, t_uint w, t_uint h)
{
	t_imgdw	imgdw;
	size_t	i;
	size_t	j;

	imgdw.img = mlx_new_image(mlx, w, h);
	imgdw.addr = mlx_get_data_addr(imgdw.img, &(imgdw.bpp),
			&(imgdw.line_w), &(imgdw.endian));
	i = 0;
	while (i < WIN_W)
	{
		j = 0;
		while (j < WIN_H / 2)
		{
			*((unsigned int *)(imgdw.addr
						+ (j * imgdw.line_w + i * imgdw.bpp / 8))) = color;
			j++;
		}
		i++;
	}
	return (imgdw.img);
}

void	img_free(void *mlx, void *img)
{
	mlx_destroy_image(mlx, img);
}
