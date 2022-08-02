/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:07:16 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/30 12:14:48 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_move_count(int a, int b, int pos_a, int pos_b)
{
	if (ft_abs(a) + ft_abs(b) > \
		ft_abs(pos_a) + ft_abs(pos_b))
		return (1);
	else
		return (0);
}

void	get_min_rotate(t_info info, int *a, int *b)
{
	int		pos_a;
	int		pos_b;
	int		index;
	int		num;
	t_node	*node;

	index = 0;
	node = info.stack_b->head;
	while (index < info.stack_b->size)
	{
		num = node->idx;
		pos_a = find_pos_a(num, info);
		if (index >= (info.stack_b->size + 1) / 2)
			pos_b = (info.stack_b->size - index) * -1;
		else
			pos_b = index;
		if (index == 0 || compare_move_count(*a, *b, pos_a, pos_b))
		{
			*a = pos_a;
			*b = pos_b;
		}
		node = node->next;
		++index;
	}
}

void	ft_sort_big_last(t_info info)
{
	int	min;
	int	min_location;

	min = min_idx(info.stack_a);
	min_location = find_pos_a_min(info);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra(info.stack_a);
			min_location--;
		}
		else
		{
			rra(info.stack_a);
			min_location++;
		}
	}
}

void	sort_large_size(t_info info)
{
	int	a;
	int	b;

	a_to_b(info);
	while (info.stack_b->size)
	{
		a = 0;
		b = 0;
		get_min_rotate(info, &a, &b);
		rotate_ab(info, &a, &b);
		rotate_a(info, a);
		rotate_b(info, b);
		pa(info);
	}
	ft_sort_big_last(info);
}
