/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:20:42 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/18 14:56:41 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate(t_all *all)
{
	int		idx_y;
	int		idx_x;
	t_point	**point;
	t_mlx	*mlx;
	t_map	*map;

	point = (all->point);
	mlx = all->mlx;
	map = all->map;
	idx_y = 0;
	while (idx_y < all->map->height)
	{
		idx_x = 0;
		while (idx_x < all->map->width)
		{
			rotate_z(idx_x - map->width / 2, idx_y - map->height / 2, \
			&point[idx_y][idx_x], mlx->handler.angle_z);
			rotate_y(point[idx_y][idx_x].trans_x, point[idx_y][idx_x].z, \
			&point[idx_y][idx_x], mlx->handler.angle_y);
			rotate_x(point[idx_y][idx_x].trans_y, point[idx_y][idx_x].trans_z, \
			&point[idx_y][idx_x], mlx->handler.angle_x);
			++idx_x;
		}
		++idx_y;
	}
}

void	draw_row(t_line *line, t_all *all)
{
	int		idx_x;
	int		idx_y;
	t_point	**point;

	point = all->point;
	idx_y = 0;
	while (idx_y < all->map->height)
	{
		idx_x = 1;
		while (idx_x < all->map->width)
		{
			line->start_x = (int)(point[idx_y][idx_x - 1].trans_x * \
			all->mlx->handler.scale + all->mlx->handler.delta_x);
			line->start_y = (int)(point[idx_y][idx_x - 1].trans_y * \
			all->mlx->handler.scale + all->mlx->handler.delta_y);
			line->finish_x = (int)(point[idx_y][idx_x].trans_x * \
			all->mlx->handler.scale + all->mlx->handler.delta_x);
			line->finish_y = (int)(point[idx_y][idx_x].trans_y * \
			all->mlx->handler.scale + all->mlx->handler.delta_y);
			line->color = point[idx_y][idx_x].color;
			bresenham(line, all);
			++idx_x;
		}
		++idx_y;
	}
}

void	draw_col(t_line *line, t_all *all)
{
	int		idx_x;
	int		idx_y;
	t_point	**point;

	point = all->point;
	idx_y = 1;
	while (idx_y < all->map->height)
	{
		idx_x = 0;
		while (idx_x < all->map->width)
		{
			line->start_x = (int)(point[idx_y - 1][idx_x].trans_x * \
			all->mlx->handler.scale + all->mlx->handler.delta_x);
			line->start_y = (int)(point[idx_y - 1][idx_x].trans_y * \
			all->mlx->handler.scale + all->mlx->handler.delta_y);
			line->finish_x = (int)(point[idx_y][idx_x].trans_x * \
			all->mlx->handler.scale + all->mlx->handler.delta_x);
			line->finish_y = (int)(point[idx_y][idx_x].trans_y * \
			all->mlx->handler.scale + all->mlx->handler.delta_y);
			line->color = point[idx_y][idx_x].color;
			bresenham(line, all);
			++idx_x;
		}
		++idx_y;
	}
}

void	draw_line(t_all *all)
{
	t_line	line;

	draw_row(&line, all);
	draw_col(&line, all);
}
