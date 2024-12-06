/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:35:06 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/06 13:25:28 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	load_canvas(t_img *img)
{
	int	endian;

	if (img->i == NULL)
		return ;
	img->a = mlx_get_data_addr(img->i, &(img->bpp), &(img->line), &endian);
	img->bpp /= 8;
}

t_img	img_load(void *mlx, char *file)
{
	t_img	img;
	int		w;
	int		h;

	img.i = mlx_xpm_file_to_image(mlx, file, &w, &h);
	if (w != TEX_W || h != TEX_H)
		img_free(mlx, &img);
	load_canvas(&img);
	return (img);
}

t_img	img_new(void *mlx, t_lvec dim)
{
	t_img	img;

	img.i = mlx_new_image(mlx, dim.x, dim.y);
	load_canvas(&img);
	return (img);
}

void	img_free(void *mlx, t_img *img)
{
	if (img->i != NULL)
	{
		mlx_destroy_image(mlx, img->i);
		img->i = NULL;
	}
}

t_color	*img_px(t_img img, t_lvec pos)
{
	return ((t_color *)(img.a + pos.y * img.line + pos.x * img.bpp));
}
