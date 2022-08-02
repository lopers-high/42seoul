/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:19:36 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/29 14:19:38 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*node;

	node = pop_tail(stack_a);
	if (node == 0)
		return ;
	push_head(stack_a, node);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack_b)
{
	t_node	*node;

	node = pop_tail(stack_b);
	if (node == 0)
		return ;
	push_head(stack_b, node);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_info info)
{
	t_node	*node;

	node = pop_tail(info.stack_a);
	if (node == 0)
		return ;
	push_head(info.stack_a, node);
	node = pop_tail(info.stack_b);
	if (node == 0)
		return ;
	push_head(info.stack_b, node);
	ft_putendl_fd("rrr", 1);
}
