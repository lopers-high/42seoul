/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:31:48 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/30 11:58:46 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	binary_search(int right, int target, int *arr)
{
	int	mid;
	int	left;

	left = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}
	return (right);
}

int	is_lis(int val, t_info info)
{
	int	i;

	i = 0;
	while (i < info.lis_len)
	{
		if (val == info.lis[i])
			return (1);
		++i;
	}
	return (0);
}

int	*put_lis(int *arr, int *record, int len, int count)
{
	int	i;
	int	j;
	int	*lis;

	i = len - 1;
	lis = ft_calloc(count + 1, sizeof(int));
	j = count;
	while (i >= 0)
	{
		if (record[i] == count)
		{
			lis[j] = arr[i];
			--j;
			--count;
		}
		--i;
	}
	return (lis);
}

void	get_lis(t_info *info, int len)
{
	int	*record;
	int	*lis;
	int	i;
	int	pos;
	int	count;

	record = ft_calloc(len, sizeof(int));
	lis = ft_calloc(len, sizeof(int));
	lis[0] = (info->arr)[0];
	i = 1;
	count = 0;
	while (i < len)
	{
		pos = binary_search(count + 1, (info->arr)[i], lis);
		if (lis[count] >= (info->arr)[i])
			lis[pos] = (info->arr)[i];
		else
			lis[++count] = (info->arr)[i];
		record[i] = pos;
		++i;
	}
	free(lis);
	info->lis = put_lis(info->arr, record, len, count);
	info->lis_len = count + 1;
	free(record);
}
