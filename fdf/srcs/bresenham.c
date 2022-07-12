/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:47:18 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/12 20:32:57 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	abs_double(double num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	bresenham_x(t_point start, t_point finish, t_all *all, int color)
{
	double	width;
	double	height;
	double	x;
	double	y;
	double	formula;
	double 	Yfactor;
	double 	Xfactor;
	double	scale;

	scale = all->mlx->handler.scale;
	width = finish.iso_x - start.iso_x;
	height = finish.iso_y - start.iso_y;
	Yfactor = 1;
	Xfactor = 1;
	if (height < 0)
	{
		Yfactor = -1;
		height *= -1;
	}
	if (width < 0)
	{
		width *= -1;
		Xfactor = -1;
	}
	x = (int)(start.iso_x * scale);
	y = start.iso_y * scale;
	double x2 = (int)(finish.iso_x * scale);
	formula = 2 * height - width;
	while (x != x2)
	{
		if (formula < 0)
			formula += (2 * height);
		else
		{
			y += Yfactor;
			formula += 2 * (height - width);
		}
		if ((int)(x + all->mlx->handler.delta_x) >= 0 && (int)(x + all->mlx->handler.delta_x) < 1600 \
			&& (int)(y + all->mlx->handler.delta_y) < 900 && (int)(y + all->mlx->handler.delta_y) >= 0)
		all->img->data[(1600 * (int)(y + all->mlx->handler.delta_y) + (int)(x + all->mlx->handler.delta_x))] = color;
		x += Xfactor;
	}
}

void	bresenham_y(t_point start, t_point finish, t_all *all, int color)
{
	double	width;
	double	height;
	double	x;
	double	y;
	double	formula;
	int		Xfactor;
	int		Yfactor;
	double	scale;

	scale = all->mlx->handler.scale;
	width = finish.iso_x - start.iso_x;
	height = finish.iso_y - start.iso_y;
	Xfactor = 1;
	Yfactor = 1;
	if (width < 0)
	{
		Xfactor = -1;
		width *= -1;
	}
	if (height < 0)
	{
		Yfactor = -1;
		height *= -1;
	}
	x = start.iso_x * scale;
	y = (int)(start.iso_y * scale);
	double y2 = (int)(finish.iso_y * scale);
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
		if ((int)(x + all->mlx->handler.delta_x) >= 0 && (int)(x + all->mlx->handler.delta_x < 1600) \
			&& (int)(y + all->mlx->handler.delta_y) < 900 && (int)(y + all->mlx->handler.delta_y) >= 0)
		all->img->data[(1600 * (int)(y + all->mlx->handler.delta_y) + \
		(int)(x + all->mlx->handler.delta_x))] = color;
		y += 1;
	}
}

void	bresenham(t_point start, t_point finish, t_all *all)
{
	double	width;
	double	height;
	int		color;

	color = finish.color;
	width = abs_double(finish.iso_x - start.iso_x);
	height = abs_double(finish.iso_y - start.iso_y);
	if (width > height)
		bresenham_x(start, finish, all, color);
	else
		bresenham_y(start, finish, all, color);
}
