/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:20:42 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/11 17:20:59 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft(t_all *all)
{
	int		idx_y;
	int		idx_x;
	t_point	**point;
	t_mlx	*mlx;
	t_map	*map;

	point = (all->point);
	mlx = (all->mlx);
	map = all->map;
	idx_y = 0;
	while (idx_y < all->map->height)
	{
		idx_x = 0;
		while (idx_x < all->map->width)
		{
			rotate_z(idx_x - map->width / 2, idx_y - map->height / 2, \
			&point[idx_y][idx_x], mlx->handler.angle_z);
			rotate_y(point[idx_y][idx_x].iso_x, point[idx_y][idx_x].z, \
			&point[idx_y][idx_x], mlx->handler.angle_y);
			rotate_x(point[idx_y][idx_x].iso_y, point[idx_y][idx_x].rotated_z, \
			&point[idx_y][idx_x], mlx->handler.angle_x);
			++idx_x;
		}
		++idx_y;
	}
}

void	draw_line(t_all *all)
{
	int		idx_y;
	int		idx_x;
	t_point	**point;
	t_map	*map;

	point = all->point;
	map = all->map;
	idx_y = 0;
	while (idx_y < map->height)
	{
		idx_x = 1;
		while (idx_x < map->width)
		{
			bresenham(point[idx_y][idx_x - 1], point[idx_y][idx_x], all);
			++idx_x;
		}
		++idx_y;
	}
	idx_y = 1;
	while (idx_y < map->height)
	{
		idx_x = 0;
		while (idx_x < map->width)
		{
			bresenham(point[idx_y - 1][idx_x], point[idx_y][idx_x], all);
			++idx_x;
		}
		++idx_y;
	}
}
