#include "wolf3d.h"

int			ft_x(int a)
{
	if (!a)
		exit(EXIT_SUCCESS);
	return (0);
}

void		draw_square(t_img *img, t_pt pt1, t_pt pt2, int wt)
{
	int y;

	while (pt1.x < pt2.x)
	{
		y = 0;
		while (y < 5)
		{
			(wt > 0) ? light_pixel(img, pt1.y + y++, pt1.x, 0xBDBDBD) : 0;
			(wt < 0) ? light_pixel(img, pt1.y + y++, pt1.x, 0xFFE0E0) : 0;
		}
		pt1.x++;
	}
}

void		t_pt_changer(t_pt *pt1, int x, int y)
{
	pt1->x = x * 5;
	pt1->y = y * 5;
}

void		worldmap(t_mlx *mlx, t_img *wmap)
{
	int		x;
	int		y;

	y = -1;
	while (++y < mlx->map.map_h)
	{
		x = -1;
		while (++x < mlx->map.map_w)
		{
			t_pt_changer(&(mlx->pt1), x, y);
			t_pt_changer(&(mlx->pt2), (x + 1), y);
			if (mlx->map.grid[y][x] != 0)
				draw_square(wmap, mlx->pt1, mlx->pt2, mlx->map.grid[y][x]);
		}
	}
}

int			main(int ac, char **av)
{
	t_mlx		mlx;

	if (ac != 2)
		ft_return_error("usage: ./wolf3d <map_name>");
	count_and_error_check(av[1], &mlx.map);
	ft_mlx_init(&mlx);
	if (!(mlx.ptr = mlx_init()) ||
			!(mlx.win = mlx_new_window(mlx.ptr, mlx.width, mlx.height, av[1])))
		ft_return_error("mlx error");
	mlx.wmap.ptr = mlx_new_image(mlx.ptr, mlx.map.map_w * 5, mlx.map.map_h * 5);
	mlx.wmap.str = mlx_get_data_addr(mlx.wmap.ptr, &(mlx.wmap.bits),
			&(mlx.wmap.line_s), &(mlx.wmap.endian));
	mlx.wmap.bits /= 8;
	worldmap(&mlx, &mlx.wmap);
	mlx_hook(mlx.win, 2, 0, key_press_hook, &mlx);
	mlx_hook(mlx.win, 3, 0, key_release_hook, &mlx);
	mlx_hook(mlx.win, 6, 0, ft_motion, &mlx);
	mlx_hook(mlx.win, 17, 0, ft_x, 0);
	mlx_loop_hook(mlx.ptr, move_loop, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
