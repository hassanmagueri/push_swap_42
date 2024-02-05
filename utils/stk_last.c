/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 05:14:24 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/24 17:20:37 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stk_last(t_stack *stk)
{
	t_stack	*cur;

	cur = stk;
	if (!stk)
		return (0);
	while (cur->next)
	{
		cur = cur->next;
	}
	return (cur);
}
