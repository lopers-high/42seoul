/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:25:48 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/18 14:56:50 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include "fdf_bonus.h"

int	mouse_click(int keycode, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		(mlx->handler.scale) += mlx->handler.scale * 0.1;
	else if (keycode == 5)
		(mlx->handler.scale) -= mlx->handler.scale * 0.1;
	return (0);
}

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_UP || keycode == KEY_DOWN || \
		keycode == KEY_RIGHT || keycode == KEY_LEFT)
		move_image(mlx, keycode);
	else if (keycode == KEY_W || keycode == KEY_S || \
		keycode == KEY_A || keycode == KEY_D || \
		keycode == KEY_Q || keycode == KEY_E)
		rotate_image(mlx, keycode);
	else if (keycode == KEY_TAB)
		parallel(&mlx->handler);
	else if (keycode == KEY_I)
		isometric(mlx);
	else if (keycode == KEY_R)
		reset_pos(mlx);
	return (0);
}

void	set_mlx(t_mlx *mlx, t_map *map)
{
	int		width;
	int		height;
	double	scale;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1600, 900, "FdF");
	ft_bzero(&mlx->handler, sizeof(t_handler));
	scale = 1;
	width = map->width;
	height = map->height;
	while (scale * width < 1000 && scale * height < 700)
		++scale;
	mlx->handler.scale = scale;
	mlx->handler.first_scale = scale;
	mlx->handler.delta_x = 800;
	mlx->handler.delta_y = 450;
}

int	main_loop(t_all *all)
{
	t_mlx	*mlx;
	t_map	*map;
	t_img	*img;

	mlx = (all->mlx);
	map = all->map;
	img = all->img;
	mlx_destroy_image(mlx->mlx, img->ptr);
	mlx_clear_window(mlx->mlx, mlx->win);
	all->img->ptr = mlx_new_image(mlx->mlx, 1600, 900);
	all->img->data = (int *)mlx_get_data_addr(img->ptr, \
		&(img->bpp), &(img->size_l), &(img->endian));
	rotate(all);
	draw_line(all);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_point	**point;
	t_mlx	mlx;
	t_all	all;

	ft_check_args(argc, argv);
	map = rec_checker(argv[1]);
	set_mlx(&mlx, &map);
	point = make_points(&map, argv[1]);
	all.map = &map;
	all.mlx = &mlx;
	all.point = point;
	all.img = ft_calloc(1, sizeof(t_img));
	all.img->ptr = mlx_new_image(mlx.mlx, 1600, 900);
	all.img->data = (int *)mlx_get_data_addr(all.img->ptr, \
		&(all.img->bpp), &(all.img->size_l), &(all.img->endian));
	mlx_hook(mlx.win, EVENT_MOUSE_CLICK, 0, mouse_click, &mlx);
	mlx_hook(mlx.win, EVENT_KEY_PRESS, 0, key_press, &mlx);
	mlx_hook(mlx.win, EVENT_CLICK_EXIT, 0, ft_exit, &mlx);
	mlx_loop_hook(mlx.mlx, main_loop, &all);
	mlx_loop(mlx.mlx);
	return (0);
}
