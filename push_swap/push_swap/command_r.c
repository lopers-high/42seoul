/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:46:14 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/29 13:46:21 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*node;

	node = pop_head(stack_a);
	if (node == 0)
		return ;
	push_tail(stack_a, node);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *stack_b)
{
	t_node	*node;

	node = pop_head(stack_b);
	if (node == 0)
		return ;
	push_tail(stack_b, node);
	ft_putendl_fd("rb", 1);
}

void	rr(t_info info)
{
	t_node	*node;

	node = pop_head(info.stack_a);
	if (node == 0)
		return ;
	push_tail(info.stack_a, node);
	node = pop_head(info.stack_b);
	if (node == 0)
		return ;
	push_tail(info.stack_b, node);
	ft_putendl_fd("rr", 1);
}
