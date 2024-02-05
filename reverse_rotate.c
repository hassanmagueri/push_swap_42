/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:44:07 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/04 14:45:15 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	reverse_rotate(t_stack **head)
{
	t_stack	*old_head;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (0);
	old_head = *head;
	*head = stk_last(*head);
	stk_before_last(old_head)->next = NULL;
	(*head)->next = old_head;
	return (1);
}

int	rra(t_stack **head_a)
{
	if (!reverse_rotate(head_a))
		return (0);
	ft_putendl_fd("rra", 1);
	return (1);
}

int	rrb(t_stack **head_b)
{
	if (!reverse_rotate(head_b))
		return (0);
	ft_putendl_fd("rrb", 1);
	return (1);
}

int	rrr(t_stack **head_a, t_stack **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	ft_putendl_fd("rrr", 1);
	return (1);
}
