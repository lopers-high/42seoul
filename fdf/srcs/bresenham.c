/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:47:18 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/11 16:02:52 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_x(t_point start, t_point finish, t_all *all, int color)
{
	double	width;
	double	height;
	double	x;
	double	y;
	double	formula;
	double 	Yfactor;
	double	scale;

	scale = all->mlx->handler.scale;
	width = finish.iso_x - start.iso_x;
	height = finish.iso_y - start.iso_y;
	Yfactor = 1;
	if (height < 0)
	{
		Yfactor = -1;
		height *= -1;
	}
	x = start.iso_x * scale;
	y = start.iso_y * scale;
	double x2 = finish.iso_x * scale;
	formula = 2 * height - width;
	while (x < x2)
	{
		if (formula < 0)
			formula += (2 * height);
		else
		{
			y += Yfactor;
			formula += 2 * (height - width);
		}
		if ((int)x + (int)all->mlx->handler.delta_x >= 0 && (int)x + (int)all->mlx->handler.delta_x < 1600 \
			&& (int)((int)y + all->mlx->handler.delta_y) < 900 && (int)((int)y + all->mlx->handler.delta_y) >= 0)
		all->img->data[(1600 * (int)((int)(y) + all->mlx->handler.delta_y) + (int)(x) + (int)all->mlx->handler.delta_x)] = color;
		x += 1;
	}
}

void	bresenham_y(t_point start, t_point finish, t_all *all, int color)
{
	double	width;
	double	height;
	double	x;
	double	y;
	double	formula;
	double	Xfactor;
	double	scale;

	scale = all->mlx->handler.scale;
	width = finish.iso_x - start.iso_x;
	height = finish.iso_y - start.iso_y;
	Xfactor = 1;
	if (width < 0)
	{
		Xfactor = -1;
		width *= -1;
	}
	x = start.iso_x * scale;
	y = start.iso_y * scale;
	double y2 = finish.iso_y * scale;
	formula = 2 * width - height;
	while (y < y2)
	{
		if (formula < 0)
			formula += (2 * width);
		else
		{
			x += Xfactor;
			formula += 2 * (width - height);
		}
		if ((int)x + (int)all->mlx->handler.delta_x >= 0 && (int)x + (int)all->mlx->handler.delta_x < 1600 \
			&& (int)((int)y + all->mlx->handler.delta_y) < 900 && (int)((int)y + all->mlx->handler.delta_y) >= 0)
		all->img->data[(1600 * (int)((int)(y) + all->mlx->handler.delta_y) + \
		(int)(x) + (int)all->mlx->handler.delta_x)] = color;
		y += 1;
	}
}

void	bresenham(t_point start, t_point finish, t_all *all)
{
	double	width;
	double	height;
	int		color;

	color = finish.color;
	width = (finish.iso_x - start.iso_x);
	if (width < 0)
		width *= -1;
	height = (finish.iso_y - start.iso_y);
	if (height < 0)
		height *= -1;
	if (width > height)
	{
		if (start.iso_x > finish.iso_x)
			bresenham_x(finish, start, all, color);
		else
			bresenham_x(start, finish, all, color);
	}
	else
	{
		if (start.iso_y > finish.iso_y)
			bresenham_y(finish, start, all, color);
		else
			bresenham_y(start, finish, all, color);
	}
}
