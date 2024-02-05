/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:52:53 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/04 14:44:13 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	max_pos(t_stack *stk)
{
	int		pos;
	t_stack	*max;
	t_stack	*head;

	head = stk;
	if (!stk)
		return (-1);
	max = stk;
	stk = stk->next;
	pos = 0;
	while (stk)
	{
		if (max->index < stk->index)
			max = stk;
		stk = stk->next;
	}
	stk = head;
	while (stk && stk != max && ++pos)
		stk = stk->next;
	return (pos);
}

int	max_pos_sec(t_stack *stk)
{
	int		pos;
	int		pos_max;
	t_stack	*max_sec;
	t_stack	*head;

	head = stk;
	pos_max = max_pos(stk);
	if (!stk)
		return (-1);
	max_sec = stk;
	stk = stk->next;
	pos = 0;
	while (stk)
	{
		pos++;
		if (max_sec->index < stk->index && pos != pos_max)
			max_sec = stk;
		stk = stk->next;
	}
	pos = 0;
	stk = head;
	while (stk && stk != max_sec && ++pos)
		stk = stk->next;
	return (pos);
}

int	abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

int	cost_pos(int pos, int size_stack)
{
	if (pos <= size_stack / 2)
		return (pos);
	return (pos - size_stack);
}

int	count_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}
