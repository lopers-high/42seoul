/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:30:46 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/30 11:49:42 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	t_node	*curr;
	int		top;
	int		mid;
	int		bottom;

	curr = stack->head;
	top = curr->idx;
	mid = curr->next->idx;
	bottom = curr->next->next->idx;
	if (mid == max_idx(stack) && top == min_idx(stack))
	{
		rra(stack);
		sa(stack);
	}
	else if (mid == min_idx(stack) && bottom == max_idx(stack))
		sa(stack);
	else if (mid == max_idx(stack) && bottom == min_idx(stack))
		rra(stack);
	else if (top == max_idx(stack) && mid == min_idx(stack))
		ra(stack);
	else if (top == max_idx(stack) && bottom == min_idx(stack))
	{
		ra(stack);
		sa(stack);
	}
}

void	sort_5(t_info info)
{
	int	idx;

	idx = find_first(info.stack_a, 0);
	while (idx <= 3 && --idx)
		ra(info.stack_a);
	while (idx > 3 && idx < 6 && idx++)
		rra(info.stack_a);
	if (is_sorted(info.stack_a))
		return ;
	pb(info);
	idx = find_first(info.stack_a, 1);
	if (idx == 2)
		sa(info.stack_a);
	while (idx > 2 && idx < 5 && idx++)
		rra(info.stack_a);
	pb(info);
	sort_3(info.stack_a);
	pa(info);
	pa(info);
}

void	sort_4(t_info info)
{
	int	idx;

	idx = find_first(info.stack_a, 0);
	while (idx <= 2 && --idx)
		ra(info.stack_a);
	while (idx > 2 && idx < 5 && idx++)
		rra(info.stack_a);
	if (is_sorted(info.stack_a))
		return ;
	pb(info);
	sort_3(info.stack_a);
	pa(info);
}

void	sort(t_info info)
{
	if (info.stack_a->size == 2)
		sa(info.stack_a);
	else if (info.stack_a->size == 3)
		sort_3(info.stack_a);
	else if (info.stack_a->size == 4)
		sort_4(info);
	else if (info.stack_a->size == 5)
		sort_5(info);
	else
		sort_large_size(info);
}
