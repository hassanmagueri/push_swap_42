/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:37:38 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/04 10:57:39 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_check(t_stack **stack_a, t_stack **stack_b, char *instr)
{
	int	len;

	len = ft_strlen(instr);
	if (!ft_strncmp("sa\n", instr, len))
		swap_first_two(stack_a);
	else if (!ft_strncmp("sb\n", instr, len))
		swap_first_two(stack_b);
	else if (!ft_strncmp("ss\n", instr, len))
	{
		swap_first_two(stack_a);
		swap_first_two(stack_b);
	}
}

void	rotate_check(t_stack **stack_a, t_stack **stack_b, char *instr)
{
	int	len;

	len = ft_strlen(instr);
	if (!ft_strncmp("ra\n", instr, len))
		rotate(stack_a);
	else if (!ft_strncmp("rb\n", instr, len))
		rotate(stack_b);
	else if (!ft_strncmp("rr\n", instr, len))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}

void	reverse_check(t_stack **stack_a, t_stack **stack_b, char *instr)
{
	int	len;

	len = ft_strlen(instr);
	if (!ft_strncmp("rra\n", instr, len))
		reverse_rotate(stack_a);
	else if (!ft_strncmp("rrb\n", instr, len))
		reverse_rotate(stack_b);
	else if (!ft_strncmp("rrr\n", instr, len))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}

void	push_check(t_stack **stack_a, t_stack **stack_b, char *instr)
{
	int	len;

	len = ft_strlen(instr);
	if (!ft_strncmp("pa\n", instr, len))
		push(stack_a, stack_b);
	else if (!ft_strncmp("pb\n", instr, len))
		push(stack_b, stack_a);
}
