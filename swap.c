/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:48:03 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/02 11:49:39 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap_first_two(t_stack **head)
{
	t_stack	*old_head;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (0);
	old_head = (*head);
	*head = (*head)->next;
	old_head->next = old_head->next->next;
	(*head)->next = old_head;
	return (1);
}

int	sa(t_stack **head_a)
{
	if (!swap_first_two(head_a))
		return (0);
	ft_putendl_fd("sa", 1);
	return (1);
}

int	sb(t_stack **head_b)
{
	if (!swap_first_two(head_b))
		return (0);
	ft_putendl_fd("sb", 1);
	return (1);
}

int	ss(t_stack **head_a, t_stack **head_b)
{
	swap_first_two(head_a);
	swap_first_two(head_b);
	ft_putendl_fd("ss", 1);
	return (1);
}
