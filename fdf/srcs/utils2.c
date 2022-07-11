/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:36:28 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/11 11:37:22 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	parse_color(char *str)
{
	int		color;

	color = 0xFFFFFF;
	while (*str && *str != 'x')
		++str;
	if (*str == 'x')
	{
		++str;
		color = ft_atoi_base(str, HEX);
	}
	if (color == 0)
		color = 0xFFFFFF;
	return (color);
}

void	get_one_line(t_point *point, int y, char *a_line, int width)
{
	char	**split;
	int		i;
	char	**tmp;
	int		x;

	i = 0;
	split = ft_split(a_line, " ");
	while (i < width)
	{
		point[i].x = i;
		point[i].y = y;
		point[i].z = ft_atoi(split[i]);
		point[i].color = parse_color(split[i]);
		i++;
	}
	tmp = split;
	while (*split)
	{
		free(*split);
		split++;
	}
	free(tmp);
}

t_point	**create_points(t_map *map)
{
	t_point	**point;
	int		i;

	point = malloc(sizeof(t_point *) * map->height);
	i = 0;
	while (i < map->height)
	{
		point[i] = malloc(sizeof(t_point) * map->width);
		i++;
	}
	return (point);
}

t_point	**make_points(t_map *map, char *file_name)
{
	t_point	**point;
	int		i;
	int		fd;
	char	*line;

	point = create_points(map);
	fd = ft_open_file(file_name);
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		get_one_line(point[i], i, line, map->width);
		free(line);
		i++;
	}
	close(fd);
	return (point);
}
