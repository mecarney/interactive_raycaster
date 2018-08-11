/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:29:17 by mcarney           #+#    #+#             */
/*   Updated: 2018/08/10 15:29:18 by mcarney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		light_pixel(t_img *img, int x, int y, unsigned int color)
{
	img->str[y * img->line_s + (x * img->bits) + 0] = color;
	img->str[y * img->line_s + (x * img->bits) + 1] = color >> 8;
	img->str[y * img->line_s + (x * img->bits) + 2] = color >> 16;
}

void		build_textures(t_mlx *mlx)
{
	int		x;
	int		y;
	int		colors[4];

	y = 0;
	while (++y <= 64)
	{
		x = 0;
		while (++x <= 64)
		{
			colors[0] = (x > 32) ? (x - 32) | y * 0x00FFFF : x | y * 0x00FFFF;
			colors[1] = (((x ^ y) % 7 * 0x0000eb) >> 1) & 0x333333;
			colors[2] = (y * 4) ^ (x * 4) * 0xFF;
			colors[3] = (((x * 0x0000FF & y * 0x0000FF)) >> 1) & 0x333333;
			mlx->tex.col[2][64 * (y - 1) + (x - 1)] =
				colors[0] + 0x100 * colors[0] + 0x10000 * colors[0];
			mlx->tex.col[3][64 * (y - 1) + (x - 1)] =
				(256 * colors[1] + 0x10000 * colors[1]);
			mlx->tex.col[1][64 * (y - 1) + (x - 1)] =
				colors[2] + 0x100 * colors[2] + 0x10000 * colors[2];
			mlx->tex.col[0][64 * (y - 1) + (x - 1)] =
				colors[3] + 0x100 * colors[3] + 0x10000 * colors[3];
		}
	}
}

void		draw(t_mlx *mlx, int *a, int x)
{
	int		y;
	int		color;
	int		depth;
	int		texy;

	y = 0;
	while (y < mlx->height)
	{
		while (y < a[1])
			light_pixel(&mlx->img, x, y++, 0xDCDCC6);
		while (y >= a[1] && y < a[2])
		{
			depth = y * 256 - mlx->height * 128 + a[0] * 128;
			texy = ((depth * 64) / a[0]) / 256;
			color = mlx->tex.col[a[3]][64 * texy + mlx->p.texx];
			light_pixel(&mlx->img, x, y++, color);
		}
		light_pixel(&mlx->img, x, y++, 0x04000);
	}
}

/*
** a[0] == lineheight a[1] == drawstart a[2] == drawend a[3] == texture
*/

void		find_lineheight(t_mlx *mlx, int side, int x)
{
	int		a[4];

	a[0] = (int)(mlx->height / mlx->p.pwalldist);
	a[1] = -a[0] / 2 + mlx->height / 2;
	(a[1] < 0) ? a[1] = 0 : 0;
	a[2] = a[0] / 2 + mlx->height / 2;
	(a[2] >= mlx->height) ? a[2] = mlx->height - 1 : 0;
	a[3] = 1;
	(side == 0 && mlx->p.raydirx < 0) ? a[3] = 2 : 0;
	(side == 1 && mlx->p.raydiry < 0) ? a[3] = 3 : 0;
	(side == 1 && mlx->p.raydiry > 0) ? a[3] = 0 : 0;
	draw(mlx, a, x);
}
