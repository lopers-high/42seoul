#include "push_swap.h"

static int	command_error(void)
{
	ft_putendl_fd("Error", 2);
	return (0);
}

static int	command_compare(char *line, t_info info)
{
	if (!ft_strncmp(line, "ra\n", 3))
		ra(info.stack_a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(info.stack_b);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(info);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(info.stack_a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(info.stack_b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(info);
	else if (!ft_strncmp(line, "sa\n", 3))
		sa(info.stack_a);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(info.stack_b);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(info);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(info);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(info);
	else
		return (command_error());
	return (1);
}

void	push_swap_read(t_info info)
{
	char	*line;
	t_node	*curr;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
		{
			is_sorted_checker(info);
			return ;
		}
		if (command_compare(line, info) == 0)
			return ;
		free(line);
	}
}

int	main(int argc, char **argv)
{
	char	**strs;
	int		ac;
	int		*arr;
	t_info	info;

	if (argc < 2)
		return (0);
	ac = parse_args(&strs, argv + 1);
	if (ac > 1)
	{
		info.stack_a = ft_calloc(1, sizeof(t_stack));
		info.stack_b = ft_calloc(1, sizeof(t_stack));
		arr = str_to_arr(0, strs, ac);
		put_value(arr, info.stack_a, ac);
		put_index(arr, info.stack_a, ac);
		push_swap_read(info);
		free(arr);
	}
	free_strs(strs);
}
