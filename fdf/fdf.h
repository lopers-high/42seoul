/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:32:17 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/18 14:53:43 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_line
{
	int	start_x;
	int	start_y;
	int	finish_x;
	int	finish_y;
	int	color;
}	t_line;

typedef struct s_bresenham
{
	int	width;
	int	height;
	int	x_factor;
	int	y_factor;
}	t_bresenham;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_handler
{
	double	first_scale;
	double	scale;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	int		delta_x;
	int		delta_y;
	int		flag;
}	t_handler;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_handler	handler;
}	t_mlx;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	double		trans_x;
	double		trans_y;
	double		trans_z;
	int			color;
}	t_point;

typedef struct s_map
{
	int	width;
	int	height;
}	t_map;

typedef struct s_all
{
	t_map		*map;
	t_mlx		*mlx;
	t_img		*img;
	t_point		**point;
}	t_all;

# define EVENT_KEY_PRESS 2
# define EVENT_MOUSE_CLICK 4
# define EVENT_CLICK_EXIT 17
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_I 34
# define KEY_TAB 48
# define HEX "0123456789abcdef"

void	rotate_x(double y, double z, t_point *point, double angle);
void	rotate_y(double x, double z, t_point *point, double angle);
void	rotate_z(double x, double y, t_point *point, double angle);
void	ft_error(char *str);
void	ft_check_args(int argc, char **argv);
int		ft_open_file(char *file_name);
t_map	rec_checker(char *file_name);
t_point	**make_points(t_map *map, char *file_name);
void	bresenham(t_line *line, t_all *all);
void	rotate(t_all *all);
void	draw_line(t_all *all);
void	parallel(t_handler *handler);
void	reset_pos(t_mlx *mlx);
int		ft_exit(void);
void	isometric(t_mlx *mlx);
void	move_image(t_mlx *mlx, int keycode);
void	rotate_image(t_mlx *mlx, int keycode);

#endif
