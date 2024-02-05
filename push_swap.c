/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:45:39 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/04 11:11:10 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char const *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	check_args(av + 1, &stack_a);
	if (is_sorted(stack_a))
		return (stk_clear(&stack_a), 0);
	else if (stk_size(stack_a) == 2)
		sa(&stack_a);
	else if (stk_size(stack_a) == 3)
		sort_tree(&stack_a, &stack_b);
	else if (stk_size(stack_a) == 4)
		sort_four(&stack_a, &stack_b);
	else if (stk_size(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
	else
		chunks_sort(&stack_a, &stack_b);
	stk_clear(&stack_a);
	return (0);
}
