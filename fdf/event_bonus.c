/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:16:26 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/18 14:56:45 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <stdlib.h>

int	ft_exit(void)
{
	exit(0);
}

void	parallel(t_handler *handler)
{
	if (handler->flag % 3 == 0)
	{
		handler->angle_x = -90;
		handler->angle_y = 0;
		handler->angle_z = 0;
	}
	else if (handler->flag % 3 == 1)
	{
		handler->angle_x = -90;
		handler->angle_y = 0;
		handler->angle_z = 90;
	}
	else if (handler->flag % 3 == 2)
	{
		handler->angle_x = 0;
		handler->angle_y = 0;
		handler->angle_z = 0;
	}
	++handler->flag;
	if (handler->flag == 100000)
		handler->flag = 1;
}

void	isometric(t_mlx *mlx)
{
	mlx->handler.angle_x = -45;
	mlx->handler.angle_y = 0;
	mlx->handler.angle_z = 35.264;
	mlx->handler.flag = 0;
}

void	rotate_image(t_mlx *mlx, int keycode)
{
	if (keycode == KEY_S)
		++(mlx->handler.angle_x);
	else if (keycode == KEY_D)
		++(mlx->handler.angle_y);
	else if (keycode == KEY_E)
		++(mlx->handler.angle_z);
	else if (keycode == KEY_W)
		--(mlx->handler.angle_x);
	else if (keycode == KEY_A)
		--(mlx->handler.angle_y);
	else if (keycode == KEY_Q)
		--(mlx->handler.angle_z);
}

void	move_image(t_mlx *mlx, int keycode)
{
	if (keycode == KEY_UP)
		(mlx->handler.delta_y) -= 30;
	else if (keycode == KEY_DOWN)
		(mlx->handler.delta_y) += 30;
	else if (keycode == KEY_LEFT)
		(mlx->handler.delta_x) -= 30;
	else if (keycode == KEY_RIGHT)
		(mlx->handler.delta_x) += 30;
}
