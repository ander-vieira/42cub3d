/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:35:06 by andeviei          #+#    #+#             */
/*   Updated: 2024/12/04 16:40:27 by andeviei         ###   ########.fr       */
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

void	*img_new(void *mlx, t_ivec2 dim)
{
	return (mlx_new_image(mlx, dim.x, dim.y));
}

void	img_free(void *mlx, void *img)
{
	mlx_destroy_image(mlx, img);
}

static t_imgdw	img_getdw(void *img)
{
	t_imgdw	dw;

	dw.addr = mlx_get_data_addr(img, &(dw.bpp), &(dw.line_w), &(dw.endian));
	dw.bpp /= 8;
	return (dw);
}

static t_uint	*pxaddr(t_imgdw dw, t_uint x, t_uint y)
{
	return ((t_uint *)(dw.addr + y * dw.line_w + x * dw.bpp));
}

void	img_px(void *img, t_uint color, t_ivec2 pos)
{
	*pxaddr(img_getdw(img), pos.x, pos.y) = color;
}

void	img_fill(void *img, t_uint color, t_ivec2 pos, t_ivec2 dim)
{
	t_imgdw	dw;
	t_ivec2	v;

	dw = img_getdw(img);
	v.x = 0;
	while (v.x < dim.x)
	{
		v.y = 0;
		while (v.y < dim.y)
		{
			*pxaddr(dw, pos.x + v.x, pos.y + v.y) = color;
			v.y++;
		}
		v.x++;
	}
}

void	img_put(void *img1, void *img2, t_ivec2 pos, t_ivec2 dim)
{
	t_imgdw	dw1;
	t_imgdw	dw2;
	t_ivec2	v;

	dw1 = img_getdw(img1);
	dw2 = img_getdw(img2);
	v.x = 0;
	while (v.x < dim.x)
	{
		v.y = 0;
		while (v.y < dim.y)
		{
			*(pxaddr(dw1, pos.x + v.x, pos.y + v.y))
				= *(pxaddr(dw2, pos.x + v.x, pos.y + v.y));
			v.y++;
		}
		v.x++;
	}
}
