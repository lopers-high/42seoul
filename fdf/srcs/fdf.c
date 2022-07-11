/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:25:48 by jinyoung          #+#    #+#             */
/*   Updated: 2022/07/11 18:50:35 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include "fdf.h"

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
}

int	mouse_action(int keycode, t_mlx *mlx)
{
	if (keycode == 1)
		(mlx->handler.delta_y) -= 30;
	else if (keycode == 2)
		(mlx->handler.delta_y) -= 30;
	else
		(mlx->handler.delta_y) -= 30;
	return (0);
}

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_UP)
		(mlx->handler.delta_y) -= 30;
	else if (keycode == KEY_DOWN)
		(mlx->handler.delta_y) += 30;
	else if (keycode == KEY_LEFT)
		(mlx->handler.delta_x) -= 30;
	else if (keycode == KEY_RIGHT)
		(mlx->handler.delta_x) += 30;
	else if (keycode == KEY_PLUS)
		(mlx->handler.scale) += mlx->handler.scale * 0.1;
	else if (keycode == KEY_MINUS)
		(mlx->handler.scale) -= mlx->handler.scale * 0.1;
	else if (keycode == KEY_S)
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
	else if (keycode == KEY_TAB)
		parallel(&mlx->handler);
	else if (keycode == KEY_I)
	{
		mlx->handler.angle_x = -45;
		mlx->handler.angle_y = 0;
		mlx->handler.angle_z = 35.264;
		mlx->handler.flag = 0;
	}
	return (0);
}

void	set_mlx(t_mlx *mlx, t_map *map)
{
	int		width;
	int		height;
	int		scale;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1600, 900, "FdF");
	ft_bzero(&mlx->handler, sizeof(t_handler));
	scale = 1;
	width = map->width;
	height = map->height;
	while (scale * width < 1000 && scale * height < 500)
		++scale;
	mlx->handler.scale = scale;
	mlx->handler.delta_x = 800;
	mlx->handler.delta_y = 450;
}

int	main_loop(t_all *all)
{
	t_point	**point;
	t_mlx	*mlx;
	t_map	*map;
	t_img	*img;

	point = (all->point);
	mlx = (all->mlx);
	map = all->map;
	img = all->img;
	mlx_destroy_image(mlx->mlx, img->ptr);
	mlx_clear_window(mlx->mlx, mlx->win);
	all->img->ptr = mlx_new_image(mlx->mlx, 1600, 900);
	all->img->data = (int *)mlx_get_data_addr(img->ptr, \
		&(img->bpp), &(img->size_l), &(img->endian));
	ft(all);
	draw_line(all);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->img->ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_point	**point;
	t_mlx	mlx;
	t_all	all;

	map = rec_checker(argv[1]);
	set_mlx(&mlx, &map);
	point = make_points(&map, argv[1]);
	all.map = &map;
	all.mlx = &mlx;
	all.point = point;
	all.img = calloc(1, sizeof(t_img));
	all.img->ptr = mlx_new_image(mlx.mlx, 1600, 900);
	all.img->data = (int *)mlx_get_data_addr(all.img->ptr, \
		&(all.img->bpp), &(all.img->size_l), &(all.img->endian));
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, key_press, &mlx);
	mlx_loop_hook(mlx.mlx, main_loop, &all);
	mlx_loop(mlx.mlx);
	return (0);
}
