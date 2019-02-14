#include "wolf3d.h"

void		add_texture(t_player *p, int side)
{
	double wallx;

	if (side == 0)
		wallx = p->posy + p->pwalldist * p->raydiry;
	else
		wallx = p->posx + p->pwalldist * p->raydirx;
	wallx -= floor(wallx);
	p->texx = (int)(wallx * 64.0);
	if (side == 0 && p->raydirx > 0)
		p->texx = 64 - p->texx - 1;
	if (side == 1 && p->raydiry < 0)
		p->texx = 64 - p->texx - 1;
}

int			walldist(t_map *map, t_player *p, int stepx, int stepy)
{
	int		hit;
	int		side;

	hit = 0;
	while (hit == 0 && map->x < map->map_w - 1 && map->y < map->map_h - 1)
	{
		if (p->sidedistx < p->sidedisty)
		{
			p->sidedistx += p->deltadistx;
			map->x += stepx;
			side = 0;
		}
		else
		{
			p->sidedisty += p->deltadisty;
			map->y += stepy;
			side = 1;
		}
		(map->grid[map->x][map->y] != 0) ? hit = 1 : 0;
	}
	p->pwalldist = (side == 0) ?
			(map->x - p->posx + (1 - stepx) / 2) / p->raydirx :
			(map->y - p->posy + (1 - stepy) / 2) / p->raydiry;
	add_texture(p, side);
	return (side);
}

int			findwall(t_map *map, t_player *p)
{
	int		stepx;
	int		stepy;

	if (p->raydirx < 0)
	{
		stepx = -1;
		p->sidedistx = (p->posx - map->x) * p->deltadistx;
	}
	else
	{
		stepx = 1;
		p->sidedistx = (map->x + 1.0 - p->posx) * p->deltadistx;
	}
	if (p->raydiry < 0)
	{
		stepy = -1;
		p->sidedisty = (p->posy - map->y) * p->deltadisty;
	}
	else
	{
		stepy = 1;
		p->sidedisty = (map->y + 1.0 - p->posy) * p->deltadisty;
	}
	return (walldist(map, p, stepx, stepy));
}

void		ft_put_and_destroy_img(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	light_pixel(&mlx->wmap, mlx->p.posx * 5, mlx->p.posy * 5, 0xCCFF00);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->wmap.ptr,
		mlx->width - mlx->map.map_w * 5 - 10, 10);
	light_pixel(&mlx->wmap, mlx->p.posx * 5, mlx->p.posy * 5, 0);
}

void		ft_raycaster(t_mlx *mlx)
{
	int		x;
	double	camerax;
	int		side;

	mlx->img.ptr = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	mlx->img.str = mlx_get_data_addr(mlx->img.ptr, &(mlx->img.bits),
			&(mlx->img.line_s), &(mlx->img.endian));
	mlx->img.bits /= 8;
	x = -1;
	while (++x < mlx->width)
	{
		camerax = 2 * x / (double)(mlx->width) - 1;
		mlx->p.raydirx = mlx->p.dx + mlx->p.plnx * camerax;
		mlx->p.raydiry = mlx->p.dy + mlx->p.plny * camerax;
		mlx->map.x = (int)(mlx->p.posx);
		mlx->map.y = (int)(mlx->p.posy);
		mlx->p.deltadistx = fabs(1 / mlx->p.raydirx);
		mlx->p.deltadisty = fabs(1 / mlx->p.raydiry);
		side = findwall(&mlx->map, &mlx->p);
		find_lineheight(mlx, side, x);
	}
	ft_put_and_destroy_img(mlx);
}
