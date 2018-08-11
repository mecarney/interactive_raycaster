/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:29:12 by mcarney           #+#    #+#             */
/*   Updated: 2018/08/10 15:29:13 by mcarney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_mlx_init(t_mlx *mlx)
{
	int		a;
	int		b;

	build_textures(mlx);
	mlx->m.first_mouse_movement = 1;
	mlx->width = (mlx->map.map_w > mlx->map.map_h ?
			mlx->map.map_w : mlx->map.map_h) * 20;
	(mlx->width < 800) ? mlx->width = 800 : (0);
	(mlx->width > 1920) ? mlx->width = 1920 : (0);
	mlx->height = mlx->width * 9 / 16;
	mlx->p.dx = -1;
	mlx->p.plny = 0.9;
	a = mlx->map.map_w;
	b = mlx->map.map_h - 1;
	while (mlx->map.grid[b][--a] != 0 && b > 0)
	{
		if (a <= 0)
		{
			a = mlx->map.map_w;
			b--;
		}
	}
	(b < 1) ? ft_return_error("Full map error") : 0;
	mlx->p.posx = a;
	mlx->p.posy = b;
}

void		fill_array(char *filename, t_map *map, int y)
{
	int		x;
	int		fd;
	char	**line_split;
	char	*line;

	if (!(map->map_h) || !(fd = open(filename, O_RDONLY)))
		ft_return_error("read error");
	while (++y < map->map_h && ft_get_next_line(fd, &line) == 1)
	{
		line_split = ft_strsplit(line, ' ');
		x = 0;
		while (line_split[x] && x < map->map_w)
			x++;
		(x == map->map_w) ? 0 : ft_return_error("map width error");
		if (!(map->grid[y] = (int *)malloc(sizeof(int) * map->map_w)))
			ft_return_error("malloc error");
		x = -1;
		while (++x < map->map_w)
			map->grid[y][x] = (x != 0 && y != 0 && y != map->map_h - 1 &&
			x != map->map_w - 1) ? ft_atoi(line_split[x]) : 1;
		ft_free_array((void**)line_split, map->map_w);
		free(line);
	}
	close(fd);
}

void		count_and_error_check(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	**line_split;

	map->map_w = 0;
	((fd = open(filename, O_RDONLY)) < 1) ? ft_return_error("read error") : 0;
	map->map_h = -1;
	while (++map->map_h >= 0 && ft_get_next_line(fd, &line) == 1)
	{
		if (!(map->map_w))
		{
			line_split = ft_strsplit(line, ' ');
			map->map_w = 0;
			while (line_split[map->map_w])
				map->map_w++;
			ft_free_array((void**)line_split, map->map_w);
		}
		free(line);
	}
	close(fd);
	(map->map_h < map->map_w) ? map->map_w = map->map_h : 0;
	(map->map_h > map->map_w) ? map->map_h = map->map_w : 0;
	if (!(map->grid = (int **)malloc(sizeof(int *) * map->map_h)))
		ft_return_error("malloc error");
	fill_array(filename, map, -1);
}
