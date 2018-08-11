/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:29:46 by mcarney           #+#    #+#             */
/*   Updated: 2018/08/10 15:29:49 by mcarney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "mlx.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_pt
{
	int			x;
	int			y;
}				t_pt;

typedef struct	s_map
{
	int			**grid;
	int			map_w;
	int			map_h;
	int			x;
	int			y;
}				t_map;

typedef struct	s_img
{
	void		*ptr;
	char		*str;
	int			bits;
	int			line_s;
	int			endian;
}				t_img;

typedef struct	s_player
{
	int			texx;
	double		od;
	double		dx;
	double		dy;
	double		opln;
	double		posx;
	double		posy;
	double		plnx;
	double		plny;
	double		sens;
	double		raydirx;
	double		raydiry;
	double		deltadistx;
	double		deltadisty;
	double		sidedistx;
	double		sidedisty;
	double		pwalldist;
}				t_player;

typedef struct	s_movement
{
	int			first_mouse_movement;
	int			f;
	int			b;
	int			l;
	int			r;
	int			l_rot;
	int			r_rot;
	int			x_old;
	double		rspeed;
}				t_movement;

typedef struct	s_tex
{
	int			col[4][4096];
	int			x;
	int			y;
}				t_tex;

typedef struct	s_mlx
{
	int			width;
	int			height;
	void		*ptr;
	void		*win;
	t_player	p;
	t_movement	m;
	t_map		map;
	t_img		img;
	t_img		wmap;
	t_pt		pt1;
	t_pt		pt2;
	t_tex		tex;
}				t_mlx;

void			count_and_error_check(char *filename, t_map *map);
void			ft_raycaster(t_mlx *mlx);
void			ft_mlx_init(t_mlx *mlx);
void			find_lineheight(t_mlx *mlx, int side, int x);
int				key_release_hook(int key, t_mlx *mlx);
int				move_loop(t_mlx *mlx);
int				ft_motion(int x, int y, t_mlx *mlx);
int				key_press_hook(int key, t_mlx *mlx);
void			light_pixel(t_img *img, int x, int y, unsigned int color);
void			build_textures(t_mlx *mlx);

#endif
