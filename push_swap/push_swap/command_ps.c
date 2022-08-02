/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:31:15 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/30 11:22:44 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_info info)
{
	t_node	*node;

	node = pop_head(info.stack_b);
	if (node == 0)
		return ;
	push_head(info.stack_a, node);
	info.stack_a->size++;
	info.stack_b->size--;
	ft_putendl_fd("pa", 1);
}

void	pb(t_info info)
{
	t_node	*node;

	node = pop_head(info.stack_a);
	if (node == 0)
		return ;
	push_head(info.stack_b, node);
	info.stack_a->size--;
	info.stack_b->size++;
	ft_putendl_fd("pb", 1);
}

void	sa(t_stack *stack_a)
{
	if (switch_stack(stack_a) == 0)
		return ;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack_b)
{
	if (switch_stack(stack_b) == 0)
		return ;
	ft_putendl_fd("sb", 1);
}

void	ss(t_info info)
{
	if (switch_stack(info.stack_a) == 0)
		return ;
	if (switch_stack(info.stack_b) == 0)
		return ;
	ft_putendl_fd("ss", 1);
}
