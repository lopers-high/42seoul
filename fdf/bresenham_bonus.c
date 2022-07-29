/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:47:18 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/18 14:56:35 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}

void	set_bresenhem_info(t_bresenham *b_data, t_line *line)
{
	b_data->width = line->finish_x - line->start_x;
	b_data->height = line->finish_y - line->start_y;
	b_data->x_factor = 1;
	b_data->y_factor = 1;
	if (b_data->height < 0)
	{
		b_data->y_factor = -1;
		b_data->height *= -1;
	}
	if (b_data->width < 0)
	{
		b_data->width *= -1;
		b_data->x_factor = -1;
	}
}

void	bresenham_x(t_line *line, t_all *all)
{
	t_bresenham	b_data;
	int			formula;

	set_bresenhem_info(&b_data, line);
	formula = 2 * b_data.height - b_data.width;
	while (line->start_x != line->finish_x)
	{
		if (formula < 0)
			formula += (2 * b_data.height);
		else
		{
			line->start_y += b_data.y_factor;
			formula += 2 * (b_data.height - b_data.width);
		}
		if ((int)(line->start_x) >= 0 && \
			(int)(line->start_x < 1600) && \
			(int)(line->start_y) < 900 && \
			(int)(line->start_y) >= 0)
		all->img->data[1600 * line->start_y + line->start_x] = line->color;
		line->start_x += b_data.x_factor;
	}
}

void	bresenham_y(t_line *line, t_all *all)
{
	t_bresenham	b_data;
	int			formula;

	set_bresenhem_info(&b_data, line);
	formula = 2 * b_data.width - b_data.height;
	while (line->start_y != line->finish_y)
	{
		if (formula < 0)
			formula += (2 * b_data.width);
		else
		{
			line->start_x += b_data.x_factor;
			formula += 2 * (b_data.width - b_data.height);
		}
		if ((int)(line->start_x) >= 0 && \
			(int)(line->start_x < 1600) && \
			(int)(line->start_y) < 900 && \
			(int)(line->start_y) >= 0)
		all->img->data[1600 * line->start_y + line->start_x] = line->color;
		line->start_y += b_data.y_factor;
	}
}

void	bresenham(t_line *line, t_all *all)
{
	int	width;
	int	height;
	int	color;

	color = line->color;
	width = ft_abs(line->finish_x - line->start_x);
	height = ft_abs(line->finish_y - line->start_y);
	if (width >= height)
		bresenham_x(line, all);
	else
		bresenham_y(line, all);
}
