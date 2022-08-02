/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:45:18 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/30 12:12:26 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_value(int *arr, t_stack *stack_a, int stack_count)
{
	int		i;
	t_node	*node;

	i = 0;
	stack_a->size = stack_count;
	while (i < stack_count)
	{
		node = ft_calloc(1, sizeof(t_node));
		node->val = arr[i];
		push_tail(stack_a, node);
		++i;
	}
}

void	free_stack(t_info info)
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
	free(info.stack_a);
	free(info.stack_b);
}

int	main(int argc, char **argv)
{
	char	**strs;
	int		stack_count;
	int		*arr;
	t_info	info;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	stack_count = parse_args(&strs, argv + 1);
	if (stack_count == 0)
		return (0);
	info.stack_a = ft_calloc(1, sizeof(t_stack));
	info.stack_b = ft_calloc(1, sizeof(t_stack));
	arr = str_to_arr(0, strs, stack_count);
	info.arr = arr;
	get_lis(&info, stack_count);
	put_value(arr, info.stack_a, stack_count);
	put_index(arr, info.stack_a, stack_count);
	if (is_sorted(info.stack_a))
		return (0);
	sort(info);
	free(arr);
	free_strs(strs);
	free_stack(info);
}
