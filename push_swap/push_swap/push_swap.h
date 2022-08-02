/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 07:43:03 by sesim             #+#    #+#             */
/*   Updated: 2022/08/02 09:38:14 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

# define MAX 2147483647
# define MIN -2147483648

typedef struct s_node
{
	int				val;
	int				idx;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef struct s_info
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*arr;
	int		*lis;
	int		lis_len;
}	t_info;

t_node	*pop_head(t_stack *stack);
t_node	*pop_tail(t_stack *stack);
void	push_head(t_stack *stack, t_node *node);
void	push_tail(t_stack *stack, t_node *node);
void	pa(t_info info);
void	pb(t_info info);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_info info);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_info info);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_info info);
void	put_value(int *arr, t_stack *stack_a, int ac);
void	put_index(int *arr, t_stack *stack, int ac);
void	sort_3(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sort_5(t_info info);
void	sort_4(t_info info);
int		min_idx(t_stack *stack);
int		max_idx(t_stack *stack);
int		find_first(t_stack *stack, int flag);
void	sort(t_info info);
void	sort_b(t_stack *stack);
void	free_strs(char **strs);
int		parse_args(char ***strs, char **argv);
int		check_sign(char c, char next_c, int *sign);
int		is_dup(int *arr, int i);
int		*str_to_arr(int i, char **strs, int ac);
int		switch_stack(t_stack *stack);
void	ft_error(char **strs);
void	sort_large_size(t_info info);
void	get_lis(t_info *info, int len);
int		is_lis(int val, t_info info);
int		find_pos_a(int num, t_info info);
int		ft_abs(int a);
void	a_to_b(t_info info);
void	rotate_ab(t_info info, int *a, int *b);
void	rotate_a(t_info info, int a);
void	rotate_b(t_info info, int b);
int		find_pos_a_min(t_info info);
#endif
