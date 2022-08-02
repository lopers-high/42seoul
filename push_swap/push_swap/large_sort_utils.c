/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:57:48 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/30 12:01:25 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos_a_max(t_info info)
{
	int		index;
	int		tmp;
	t_node	*node;
	int		ret;

	ret = 0;
	tmp = 0;
	node = info.stack_a->head;
	index = max_idx(info.stack_a);
	while (node)
	{
		tmp = node->idx;
		if (tmp == index)
			break ;
		ret++;
		node = node->next;
	}
	ret++;
	if (ret >= (info.stack_a->size + 1) / 2)
		ret = (info.stack_a->size - ret) * -1;
	return (ret);
}

int	find_pos_a_mid(int num, t_info info)
{
	t_node	*node;
	int		ret;

	node = info.stack_a->head;
	ret = 1;
	while (node->next)
	{
		if (num > node->idx && num < node->next->idx)
			break ;
		ret++;
		node = node->next;
	}
	if (ret >= (info.stack_a->size + 1) / 2)
		ret = (info.stack_a->size - ret) * -1;
	return (ret);
}

int	find_pos_a_min(t_info info)
{
	int			index;
	int			tmp;
	t_node		*node;
	int			ret;

	ret = 0;
	tmp = 0;
	node = info.stack_a->head;
	index = min_idx(info.stack_a);
	while (node)
	{
		tmp = node->idx;
		if (tmp == index)
			break ;
		ret++;
		node = node->next;
	}
	if (ret >= (info.stack_a->size + 1) / 2)
		ret = (info.stack_a->size - ret) * -1;
	return (ret);
}

int	find_pos_a(int num, t_info info)
{
	int	a;

	if (num < min_idx(info.stack_a))
		return (find_pos_a_min(info));
	else if (num > max_idx(info.stack_a))
		return (find_pos_a_max(info));
	else
		return (find_pos_a_mid(num, info));
}

int	ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}
