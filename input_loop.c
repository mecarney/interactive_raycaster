#include "wolf3d.h"

void	move_rotation(t_mlx *mlx, double rspeed)
{
	if (mlx->m.r_rot)
	{
		mlx->p.od = mlx->p.dx;
		mlx->p.dx = mlx->p.dx * cos(-rspeed) - mlx->p.dy * sin(-rspeed);
		mlx->p.dy = mlx->p.od * sin(-rspeed) + mlx->p.dy * cos(-rspeed);
		mlx->p.opln = mlx->p.plnx;
		mlx->p.plnx = mlx->p.plnx * cos(-rspeed) - mlx->p.plny * sin(-rspeed);
		mlx->p.plny = mlx->p.opln * sin(-rspeed) + mlx->p.plny * cos(-rspeed);
	}
	else
	{
		mlx->p.od = mlx->p.dx;
		mlx->p.dx = mlx->p.dx * cos(rspeed) - mlx->p.dy * sin(rspeed);
		mlx->p.dy = mlx->p.od * sin(rspeed) + mlx->p.dy * cos(rspeed);
		mlx->p.opln = mlx->p.plnx;
		mlx->p.plnx = mlx->p.plnx * cos(rspeed) - mlx->p.plny * sin(rspeed);
		mlx->p.plny = mlx->p.opln * sin(rspeed) + mlx->p.plny * cos(rspeed);
	}
	if (mlx->m.rspeed != 0)
		mlx->m.rspeed = 0;
}

void	move_forward(t_mlx *mlx, double movespeed)
{
	if (mlx->m.f)
	{
		if ((mlx->map.grid[(int)(mlx->p.posx + mlx->p.dx)]
					[(int)(mlx->p.posy + mlx->p.dy)]) < 1)
		{
			mlx->p.posx += mlx->p.dx * movespeed;
			mlx->p.posy += mlx->p.dy * movespeed;
		}
	}
	else
	{
		if (!(mlx->map.grid[(int)(mlx->p.posx - mlx->p.dx)]
					[(int)(mlx->p.posy - mlx->p.dy)]))
		{
			mlx->p.posx += mlx->p.dx * -movespeed;
			mlx->p.posy += mlx->p.dy * -movespeed;
		}
	}
}

void	move_left(t_mlx *mlx, double movespeed)
{
	if (mlx->m.l)
	{
		if (!(mlx->map.grid[(int)(mlx->p.posx - mlx->p.dy)]
					[(int)(mlx->p.posy + mlx->p.dx)]))
		{
			mlx->p.posx -= mlx->p.dy * movespeed;
			mlx->p.posy += mlx->p.dx * movespeed;
		}
	}
	else
	{
		if (!(mlx->map.grid[(int)(mlx->p.posx + mlx->p.dy)]
					[(int)(mlx->p.posy - mlx->p.dx)]))
		{
			mlx->p.posx -= mlx->p.dy * -movespeed;
			mlx->p.posy += mlx->p.dx * -movespeed;
		}
	}
}

int		move_loop(t_mlx *mlx)
{
	double	movespeed;
	double	rspeed;

	movespeed = 0.00007 * mlx->width;
	rspeed = 0.00003 * mlx->width;
	if (mlx->m.f || mlx->m.b)
		move_forward(mlx, movespeed);
	if (mlx->m.l || mlx->m.r)
		move_left(mlx, movespeed);
	if (mlx->m.r_rot || mlx->m.l_rot)
		move_rotation(mlx, rspeed);
	if (mlx->m.rspeed != 0)
		move_rotation(mlx, mlx->m.rspeed);
	ft_raycaster(mlx);
	return (0);
}
