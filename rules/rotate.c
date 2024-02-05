/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:45:44 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/04 01:37:47 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(t_stack **head)
{
	t_stack	*old_head;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (0);
	old_head = *head;
	*head = (*head)->next;
	stk_last(old_head)->next = old_head;
	old_head->next = NULL;
	return (1);
}

int	ra(t_stack **head_a)
{
	if (!rotate(head_a))
		return (0);
	ft_putendl_fd("ra", 1);
	return (1);
}

int	rb(t_stack **head_a)
{
	if (!rotate(head_a))
		return (0);
	ft_putendl_fd("rb", 1);
	return (1);
}

int	rr(t_stack **head_a, t_stack **head_b)
{
	rotate(head_a);
	rotate(head_b);
	ft_putendl_fd("rr", 1);
	return (1);
}
