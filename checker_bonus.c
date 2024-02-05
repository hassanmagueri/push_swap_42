/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:39:41 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/03 21:40:28 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stks_clear(t_stack **stk_a, t_stack **stk_b)
{
	stk_clear(stk_a);
	stk_clear(stk_b);
}

void	read_instration_set_stack(t_stack **stk_a, t_stack **stk_b)
{
	char	*str;
	int		len;

	str = get_next_line(0);
	while (str)
	{
		len = ft_strlen(str);
		if (!ft_strncmp("sa\n", str, len) || !ft_strncmp("sb\n", str, len)
			|| !ft_strncmp("ss\n", str, len))
			swap_check(stk_a, stk_b, str);
		else if (!ft_strncmp("ra\n", str, len)
			|| !ft_strncmp("rb\n", str, len) || !ft_strncmp("rr\n", str, len))
			rotate_check(stk_a, stk_b, str);
		else if (!ft_strncmp("rra\n", str, len)
			|| !ft_strncmp("rrb\n", str, len)
			|| !ft_strncmp("rrr\n", str, len))
			reverse_check(stk_a, stk_b, str);
		else if (!ft_strncmp("pa\n", str, len) || !ft_strncmp("pb\n", str, len))
			push_check(stk_a, stk_b, str);
		else
			return (stks_clear(stk_a, stk_b), free_print_error_exit(str));
		free(str);
		str = get_next_line(0);
	}
	free(str);
}

int	main(int ac, char const *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	check_args(av + 1, &stack_a);
	read_instration_set_stack(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stk_size(stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	stk_clear(&stack_a);
	stk_clear(&stack_b);
	return (0);
}
