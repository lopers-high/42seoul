/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:35:46 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/18 14:40:03 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include "fdf.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

int	ft_open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("read fail");
	return (fd);
}

void	ft_check_args(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		ft_error("Wrong Arguments");
	i = 0;
	while (argv[1][i])
	{
		if (ft_strncmp(argv[1] + i - 1, ".fdf\0", 5) == 0)
			return ;
		++i;
	}
	ft_error("Wrong File Name");
}

t_map	rec_checker(char *file_name)
{
	char	*line;
	int		col_count;
	int		row_count;
	t_map	map;
	int		fd;

	fd = ft_open_file(file_name);
	line = get_next_line(fd);
	col_count = count_str(line, " \t\n");
	row_count = 0;
	while (line)
	{
		if (count_str(line, " \t\n") != col_count)
			ft_error("Invalid Map");
		++row_count;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	line = NULL;
	map.width = col_count;
	map.height = row_count;
	return (map);
}
