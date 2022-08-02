/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:49:39 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/30 10:50:37 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quick_sort(int *arr, int l, int r)
{
	int	left;
	int	right;
	int	pivot;

	pivot = arr[(l + r) / 2];
	left = l;
	right = r;
	while (left <= right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
			ft_swap(&arr[left++], &arr[right--]);
	}
	if (l < right)
		quick_sort(arr, l, right);
	if (r > left)
		quick_sort(arr, left, r);
}

void	put_index(int *arr, t_stack *stack, int ac)
{
	t_node	*curr;
	int		i;

	curr = stack->head;
	quick_sort(arr, 0, ac - 1);
	while (curr)
	{
		i = 0;
		while (i < ac)
		{
			if (arr[i] == curr->val)
			{
				curr->idx = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
}
