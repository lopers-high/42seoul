/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:24:45 by sesim             #+#    #+#             */
/*   Updated: 2022/07/30 11:22:15 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_head(t_stack *stack, t_node *node)
{
	t_node	*curr;

	curr = stack->head;
	if (curr == 0)
	{
		stack->head = node;
		stack->tail = node;
		return ;
	}
	node->next = stack->head;
	stack->head = node;
}

void	push_tail(t_stack *stack, t_node *node)
{
	t_node	*curr;

	curr = stack->head;
	if (curr == 0)
	{
		stack->head = node;
		stack->tail = node;
		return ;
	}
	while (curr->next != 0)
		curr = curr->next;
	curr->next = node;
	stack->tail = node;
}

t_node	*pop_head(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	if (node == 0)
		return (0);
	stack->head = node->next;
	node->next = 0;
	return (node);
}

t_node	*pop_tail(t_stack *stack)
{
	t_node	*curr;
	t_node	*res;

	curr = stack->head;
	if (curr == 0)
	{
		ft_putendl_fd("pop _err", 1);
		return (0);
	}
	while (curr->next != stack->tail)
		curr = curr->next;
	res = stack->tail;
	stack->tail = curr;
	curr->next = 0;
	return (res);
}

int	switch_stack(t_stack *stack)
{
	int	tmp;

	if (stack->head == 0 || stack->head->next == 0)
		return (0);
	tmp = stack->head->val;
	stack->head->val = stack->head->next->val;
	stack->head->next->val = tmp;
	tmp = stack->head->idx;
	stack->head->idx = stack->head->next->idx;
	stack->head->next->idx = tmp;
	return (1);
}
