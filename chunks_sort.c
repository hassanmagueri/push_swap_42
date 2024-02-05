/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:52:50 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/04 17:33:51 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	pm_low_cost(int pos_a, int pos_b, int size)
{
	int	cost_a;
	int	cost_b;

	cost_a = count_cost(pos_a, size);
	cost_b = count_cost(pos_b, size);
	if (cost_a <= cost_b)
		return (1);
	return (0);
}

void	push_max(t_stack **stack_a, t_stack **stack_b, int pos_max, int max_i)
{
	int	(*instraction)(t_stack **);

	instraction = rb;
	if (pos_max > stk_size(*stack_b) / 2)
		instraction = rrb;
	while (stack_b && (*stack_b)->index != max_i)
		instraction(stack_b);
	pa(stack_a, stack_b);
}

void	push_back(t_stack **stack_a, t_stack **stack_b)
{
	int	pos_max;
	int	pos_sec_max;

	while (*stack_b)
	{
		pos_max = max_pos(*stack_b);
		pos_sec_max = max_pos_sec(*stack_b);
		if (pm_low_cost(pos_max, pos_sec_max, stk_size(*stack_b)))
			push_max(stack_a, stack_b, pos_max, stk_size(*stack_b) - 1);
		else
		{
			push_max(stack_a, stack_b, pos_sec_max, stk_size(*stack_b) - 2);
			push_max(stack_a, stack_b, pos_max, stk_size(*stack_b));
			sa(stack_a);
		}
	}
}

void	push_chunk(t_stack **stack_a, t_stack **stack_b, int chk_sz, int med)
{
	if ((*stack_a) && (*stack_a)->index < chk_sz)
	{
		if ((*stack_a)->index >= med)
		{
			pb(stack_b, stack_a);
			if ((*stack_a) && (*stack_a)->index >= chk_sz)
				rr(stack_a, stack_b);
			else
				rb(stack_b);
		}
		else
			pb(stack_b, stack_a);
	}
	else
		ra(stack_a);
}

int	chunks_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		chunk_size;
	int		chunk_tmp_size;
	int		med;
	t_stack	*cur;

	chunk_size = stk_size(*stack_a) / 5;
	if (stk_size(*stack_a) > 100)
		chunk_size = stk_size(*stack_a) / 9;
	chunk_tmp_size = chunk_size;
	med = chunk_size / 2;
	cur = *stack_a;
	while (*stack_a)
	{
		push_chunk(stack_a, stack_b, chunk_size, med);
		if (stk_size(*stack_b) == chunk_size)
		{
			med += chunk_tmp_size;
			chunk_size += chunk_tmp_size;
		}
	}
	push_back(stack_a, stack_b);
	return (1);
}
