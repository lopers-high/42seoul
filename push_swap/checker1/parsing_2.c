#include "push_swap.h"

int	parse_args(char ***strs, char **argv)
{
	char	*line;
	char	*tmp;
	int		ret;

	ret = 0;
	line = 0;
	while (*argv)
	{
		if (!line)
			line = ft_strdup(*argv++);
		else
		{
			tmp = line;
			line = ft_strjoin(line, " ");
			free (tmp);
			tmp = line;
			line = ft_strjoin(line, *argv++);
			free (tmp);
		}
	}
	*strs = ft_split(line, ' ');
	free (line);
	while ((*strs)[ret])
		ret++;
	return (ret);
}

int	check_sign(char c, char next_c, int *sign)
{
	if (c == '+' && ft_isdigit(next_c))
		return (1);
	else if (c == '-' && ft_isdigit(next_c))
	{
		*sign = -1;
		return (1);
	}
	else
		return (0);
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	ft_error(char **strs)
{
	free_strs(strs);
	ft_putendl_fd("Error", 2);
	exit (1);
}

int	is_dup(int *arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (arr[i] == arr[j])
		{
			free(arr);
			return (1);
		}
		j++;
	}
	return (0);
}
