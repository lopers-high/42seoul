/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:06:19 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/21 18:43:42 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "./gnl/get_next_line.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#define abs(a) a >= 0 ? a : a * -1

void	dda(float x1, float y1, float x2, float y2, void *mlx, void *window, int n)
{
	float dx, dy, xinc, yinc, step, i = 0.0;

    dx = x2 - x1;
    dy = y2 - y1;
    // dx는 x좌표의 차이, dy는 y좌표의 차이

    if (abs(dx) > abs(dy))
    	step = abs(dx);
    else
    	step = abs(dy);
    // dx > dy : 기울기가 1보다 작을경우
    // dx < dy : 기울기가 1보다 클 경우

    xinc = dx / step;
    yinc = dy / step;
    while (i <= step)
    {
		if (n == 1)
    		mlx_pixel_put(mlx, window, x1, y1, 0xFF0000);
		else
			mlx_pixel_put(mlx, window, x1, y1, 0xFFFFFF);
        x1 = x1 + xinc;
        y1 = y1 + yinc;
		i += 1.0;
    }
}
int main(int ac, char **av)
{
	void	*mlx;
	void	*window;
	// char	*line;
	int		fd;
	// int		x;
	int		y;
	// char	**split;
	int ft[10][9] = {{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,1,1,0,0,1,1,0},{0,0,1,1,0,0,1,1,0},{0,0,1,1,0,0,1,1,0},{0,0,1,1,1,1,1,1,0},{0,0,0,1,1,1,1,1,0},{0,0,0,0,0,0,1,1,0}, {0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}};
	ac = 0;
	y = 0;
	mlx = mlx_init();
	window = mlx_new_window(mlx, 700, 700, "FdF");
	fd = open(av[1], O_RDONLY);
	// while ((line = get_next_line(fd)))
	// {
	// 	split = ft_split(line, ' ');
	// 	x = 0;
	// 	while (*split)
	// 	{
	// 		if (0 < ft_atoi(*split))
	// 			mlx_pixel_put(mlx, window, 100 + x, 200 + y, 0xFF00FF);
	// 		else if (ft_atoi(*split) == 0)
	// 			mlx_pixel_put(mlx, window, 100 + x, 200 + y, 0xFFFFFF);
	// 		split++;
	// 		x += 25;
	// 	}
	// 	y += 25;
	// }
	for (int y = 0; y < 200; y += 20)
	{
		for (int x = 0; x < 180; x += 20)
		{
			if (y == 0 && x ==0)
				mlx_pixel_put(mlx,window, 100, 100, 0xFFFF00);
			else if (ft[y/20][x/20] == 1)
			{
				dda(100+(x-20), 100+y, 100+x, 100+y, mlx, window, 1);
			}
			else if (ft[y/20][x/20] == 0 && x != 0)
				dda(100+(x-20),100+ y,100+ x, 100+y, mlx, window, 0);
			printf("x : %d, y : %d, v : %d\n", x, y, ft[y/20][x/20]);
		}
	}


	for (int x = 0; x < 180; x += 20)
	{
		for (int y = 0; y < 200; y += 20)
		{
			if (y == 0 && x ==0)
				mlx_pixel_put(mlx,window, 100, 100, 0xFFFFFF);
			else if (ft[y/20][x/20] == 1)
				dda(100+x, 100+(y - 20) , 100+x, 100+y, mlx, window, 1);
			else if (ft[y/20][x/20] == 0 && y != 0)
				dda(100+x, 100+(y - 20) , 100+x, 100+y, mlx, window, 0);
		}
	}
	mlx_loop(mlx);
}


// [0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,1,1,0,0,1,1,0],[0,0,1,1,0,0,1,1,0],[0,0,1,1,0,0,1,1,0],[0,0,1,1,1,1,1,1,0],[0,0,0,1,1,1,1,1,0],[0,0,0,0,0,0,1,1,0]


// 0	0	0	0	0	0

// 0	0	1	1	0	0

// 0	0	0	0	0	0

// 0	0	0	0	0	0
