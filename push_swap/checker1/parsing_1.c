#include "push_swap.h"

void	put_value(int *arr, t_stack *stack_a, int ac)
{
	int		i;
	t_node	*node;

	i = 0;
	stack_a->size = ac;
	while (i < ac)
	{
		node = ft_calloc(1, sizeof(t_node));
		node->val = arr[i];
		push_tail(stack_a, node);
		++i;
	}
}

void	struct_free(t_info info)
{
	t_node	*curr;
	t_node	*tmp;

	curr = info.stack_a->head;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		tmp->val = 0;
		tmp->idx = 0;
		free(tmp);
	}
}

void	is_sorted_checker(t_info info)
{
	t_node	*curr;

	curr = info.stack_a->head;
	while (curr->next)
	{
		if (curr->val > curr->next->val)
		{
			ft_putendl_fd("KO", 1);
			return ;
		}
		curr = curr->next;
	}
	if (info.stack_b->size != 0)
	{
		ft_putendl_fd("KO", 1);
		return ;
	}
	ft_putendl_fd("OK", 1);
}

int	*init_arr(char **strs, int ac)
{
	int	*arr;

	arr = ft_calloc(1, sizeof(int) * ac);
	if (arr == 0)
		ft_error(strs);
	return (arr);
}

int	*str_to_arr(int i, char **strs, int ac)
{
	long long	num;
	int			j;
	int			sign;
	int			*arr;

	arr = init_arr(strs, ac);
	while (strs[i])
	{
		num = 0;
		sign = 1;
		j = check_sign(strs[i][0], strs[i][1], &sign);
		while (strs[i][j])
		{
			if (!(strs[i][j] >= '0' && strs[i][j] <= '9'))
				ft_error(strs);
			num += num * 10 + strs[i][j++] - '0';
		}
		if ((num > MAX && sign == 1) || (sign == -1 && num * sign < MIN))
			ft_error(strs);
		arr[i] = sign * num;
		if (is_dup(arr, i++))
			ft_error(strs);
	}
	return (arr);
}
