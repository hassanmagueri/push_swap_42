/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:41:16 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/04 14:49:24 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	free_tab(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}

int	check_dup(t_stack **stack_a, char **arrs, int nbr)
{
	t_stack	*head;

	head = (*stack_a);
	while (head)
	{
		if (head->nbr == nbr)
		{
			stk_clear(stack_a);
			free_tab(arrs);
			print_error_exit();
		}
		head = head->next;
	}
	return (0);
}

int	is_sorted(t_stack *stk)
{
	while (stk && stk->next)
	{
		if (stk->nbr > stk->next->nbr)
			return (0);
		stk = stk->next;
	}
	return (1);
}
