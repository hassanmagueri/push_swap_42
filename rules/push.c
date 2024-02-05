/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:41:57 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/02 11:43:15 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*new_head_b;

	if (stk_b == NULL || *stk_b == NULL)
		return (0);
	new_head_b = (*stk_b)->next;
	stk_add_front(stk_a, *stk_b);
	(*stk_b) = new_head_b;
	return (1);
}

int	pa(t_stack **stk_a, t_stack **stk_b)
{
	if (!push(stk_a, stk_b))
		return (0);
	ft_putendl_fd("pa", 1);
	return (1);
}

int	pb(t_stack **stk_b, t_stack **stk_a)
{
	if (!push(stk_b, stk_a))
		return (0);
	ft_putendl_fd("pb", 1);
	return (1);
}
