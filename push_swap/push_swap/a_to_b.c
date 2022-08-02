/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:00:34 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/30 12:39:04 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_four(t_info info, int pivot1, int pivot2, int pivot3)
{
	if (is_lis(info.stack_a->head->val, info))
		ra(info.stack_a);
	else if (info.stack_a->head->idx >= pivot1 && \
			info.stack_a->head->idx < pivot2)
	{
		pb(info);
		rb(info.stack_b);
	}
	else if (info.stack_a->head->idx >= pivot2 && \
			info.stack_a->head->idx < pivot3)
		pb(info);
	else
		ra(info.stack_a);
}

void	divide_four2(t_info info, int pivot1)
{
	if (is_lis(info.stack_a->head->val, info))
		ra(info.stack_a);
	else if (info.stack_a->head->idx < pivot1)
	{
		pb(info);
		rb(info.stack_b);
	}
	else
		pb(info);
}

void	a_to_b(t_info info)
{
	int	index;
	int	pivot1;
	int	pivot2;
	int	pivot3;

	pivot1 = info.stack_a->size / 4;
	pivot2 = info.stack_a->size / 2;
	pivot3 = info.stack_a->size * 3 / 4;
	index = info.stack_a->size;
	while (index)
	{
		divide_four(info, pivot1, pivot2, pivot3);
		index--;
	}
	index = info.stack_a->size;
	while (index)
	{
		divide_four2(info, pivot1);
		index--;
		if (info.stack_a->size == 3)
		{
			sort_3(info.stack_a);
			return ;
		}
	}
}
