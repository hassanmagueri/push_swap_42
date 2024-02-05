/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:22:37 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/04 17:33:15 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	str_to_num(const char *str, t_stack **stack_a, char **arrs)
{
	long	num;
	int		s;
	int		i;

	i = 0;
	num = 0;
	s = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			s = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i++] - 48;
		if ((num > INT_MAX && s == 1) || ((num * -1) < INT_MIN && s == -1))
			return (stk_clear(stack_a), free_tab(arrs), print_error_exit(), 0);
	}
	if (str[i] != 0 || str[i - 1] == '-' || str[i - 1] == '+')
		return (stk_clear(stack_a), free_tab(arrs), print_error_exit(), 0);
	return (num * s);
}

void	set_index(t_stack **stack_a)
{
	t_stack	*cur;
	t_stack	*min;
	int		index;

	index = 0;
	cur = *stack_a;
	while (cur)
	{
		if (cur->index == -1)
		{
			min = cur;
			while (cur)
			{
				if (cur->nbr < min->nbr && cur->index == -1)
					min = cur;
				cur = cur->next;
			}
			min->index = index++;
			cur = *stack_a;
		}
		else
			cur = cur->next;
	}
}

void	add_to_stack_a(char **arrs, t_stack **stack_a)
{
	int		j;
	int		nbr;
	t_stack	*node;

	j = 0;
	while (arrs[j])
	{
		nbr = str_to_num(arrs[j], stack_a, arrs);
		check_dup(stack_a, arrs, nbr);
		node = stk_new(nbr, -1);
		if (!node)
			return (free_tab(arrs), stk_clear(stack_a), print_error_exit());
		stk_add_back(stack_a, node);
		j++;
	}
}

void	check_args(char const *av[], t_stack **stack_a)
{
	int		i;
	char	**arrs;

	i = 0;
	while (av[i])
	{
		arrs = ft_split(av[i], ' ');
		if (!arrs)
			return (stk_clear(stack_a), print_error_exit());
		if (arrs[0] == NULL)
			return (free_tab(arrs), stk_clear(stack_a), print_error_exit());
		add_to_stack_a(arrs, stack_a);
		free_tab(arrs);
		i++;
	}
	set_index(stack_a);
}
