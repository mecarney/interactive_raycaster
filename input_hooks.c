#include "wolf3d.h"

int		ft_motion(int x, int y, t_mlx *mlx)
{
	double rspeed;

	y += 0;
	rspeed = 0.008;
	if (!mlx->m.first_mouse_movement)
	{
		rspeed *= abs(x - mlx->m.x_old);
		if (x > mlx->m.x_old)
			rspeed *= -1;
		mlx->m.rspeed = rspeed;
	}
	else
		mlx->m.first_mouse_movement = 0;
	mlx->m.x_old = x;
	return (0);
}

int		key_press_hook(int key, t_mlx *mlx)
{
	(key == 14) ? mlx->m.r_rot = 1 : 0;
	(key == 12) ? mlx->m.l_rot = 1 : 0;
	(key == 13 || key == 126) ? mlx->m.f = 1 : 0;
	(key == 1 || key == 125) ? mlx->m.b = 1 : 0;
	(key == 0 || key == 123) ? mlx->m.l = 1 : 0;
	(key == 2 || key == 124) ? mlx->m.r = 1 : 0;
	if (key == 53)
	{
		mlx_destroy_image(mlx->ptr, mlx->wmap.ptr);
		mlx_destroy_window(mlx->ptr, mlx->win);
		exit(EXIT_SUCCESS);
	}
	if (key == 8)
	{
		mlx->p.dx = -1;
		mlx->p.dy = 0;
		mlx->p.plnx = 0;
		mlx->p.plny = 0.9;
	}
	return (0);
}

int		key_release_hook(int key, t_mlx *mlx)
{
	if (key == 13 || key == 126)
		mlx->m.f = 0;
	else if (key == 1 || key == 125)
		mlx->m.b = 0;
	else if (key == 0 || key == 123)
		mlx->m.l = 0;
	else if (key == 2 || key == 124)
		mlx->m.r = 0;
	else if (key == 14)
		mlx->m.r_rot = 0;
	else if (key == 12)
		mlx->m.l_rot = 0;
	return (0);
}
