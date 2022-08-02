/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:13:27 by jinypark          #+#    #+#             */
/*   Updated: 2022/07/30 12:14:38 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ab(t_info info, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(info);
		--*a;
		--*b;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(info);
		++*a;
		++*b;
	}
}

void	rotate_a(t_info info, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(info.stack_a);
			--a;
		}
		else
		{
			rra(info.stack_a);
			++a;
		}
	}
}

void	rotate_b(t_info info, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(info.stack_b);
			--b;
		}
		else
		{
			rrb(info.stack_b);
			++b;
		}
	}
}
