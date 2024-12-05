/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:35:06 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/05 17:06:23 by andeviei         ###   ########.fr       */
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
		return (mlx_destroy_image(mlx, img), NULL);
	return (img);
}

void	*img_new(void *mlx, t_lvec dim)
{
	return (mlx_new_image(mlx, dim.x, dim.y));
}

void	img_free(void *mlx, void *img)
{
	mlx_destroy_image(mlx, img);
}

t_cnv	img_cnv(void *img)
{
	t_cnv	cnv;

	cnv.addr = mlx_get_data_addr(img, &(cnv.bpp), &(cnv.line_w), &(cnv.endian));
	cnv.bpp /= 8;
	return (cnv);
}

t_color	*img_px(t_cnv cnv, t_lvec pos)
{
	return ((t_color *)(cnv.addr + pos.y * cnv.line_w + pos.x * cnv.bpp));
}
