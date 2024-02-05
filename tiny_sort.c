/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:27:39 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/04 15:41:23 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_instra(int (*instra)(t_stack **), t_stack **stack_a)
{
	instra(stack_a);
	instra(stack_a);
}

void	sort_tree(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;

	min_index = stk_size(*stack_b);
	if (is_sorted(*stack_a))
		return ;
	if ((*stack_a)->index == 1 + min_index
		&& (*stack_a)->next->index == 0 + min_index)
		sa(stack_a);
	else if ((*stack_a)->index == 2 + min_index
		&& (*stack_a)->next->index == 1 + min_index)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if ((*stack_a)->index == 2 + min_index
		&& (*stack_a)->next->index == 0 + min_index)
		ra(stack_a);
	else if ((*stack_a)->index == 1 + min_index
		&& (*stack_a)->next->index == 2 + min_index)
		rra(stack_a);
	else
	{
		sa(stack_a);
		ra(stack_a);
	}
}

int	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		i;
	int		min_index;

	i = 0;
	min_index = 0;
	if (stk_size(*stack_b))
		min_index = 1;
	min = *stack_a;
	while (min && min->index != min_index && ++i)
		min = min->next;
	if (i == 1)
		sa(stack_a);
	else if (i == 2)
		apply_instra(rra, stack_a);
	else if (i == 3)
		rra(stack_a);
	if (is_sorted(*stack_a))
		return (1);
	pb(stack_b, stack_a);
	sort_tree(stack_a, stack_b);
	pa(stack_a, stack_b);
	return (1);
}

int	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		i;

	i = 0;
	min = *stack_a;
	while (min && min->index != 0 && ++i)
		min = min->next;
	if (i == 1)
		sa(stack_a);
	else if (i == 2)
		apply_instra(ra, stack_a);
	else if (i == 3)
		apply_instra(rra, stack_a);
	else if (i == 4)
		rra(stack_a);
	if (is_sorted(*stack_a))
		return (1);
	pb(stack_b, stack_a);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
	return (1);
}
