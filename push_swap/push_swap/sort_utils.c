/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:47:13 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/30 11:47:27 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_idx(t_stack *stack)
{
	t_node	*curr;
	int		tmp;

	curr = stack->head;
	tmp = curr->idx;
	while (curr->next)
	{
		if (tmp > curr->next->idx)
			tmp = curr->next->idx;
		curr = curr->next;
	}
	return (tmp);
}

int	max_idx(t_stack *stack)
{
	t_node	*curr;
	int		tmp;

	curr = stack->head;
	tmp = curr->idx;
	while (curr->next)
	{
		if (tmp < curr->next->idx)
			tmp = curr->next->idx;
		curr = curr->next;
	}
	return (tmp);
}

int	is_sorted(t_stack *stack)
{
	t_node	*curr;

	curr = stack->head;
	while (curr->next)
	{
		if (curr->idx > curr->next->idx)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	find_first(t_stack *stack, int flag)
{
	t_node	*curr;
	int		i;

	i = 1;
	curr = stack->head;
	while (curr)
	{
		if (curr->idx == flag)
			break ;
		curr = curr->next;
		i++;
	}
	return (i);
}
