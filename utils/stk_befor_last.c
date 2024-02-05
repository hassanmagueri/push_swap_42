/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_befor_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 05:14:24 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/24 18:22:10 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stk_before_last(t_stack *stk)
{
	t_stack	*cur;

	cur = stk;
	if (!stk)
		return (0);
	while (cur->next->next)
	{
		cur = cur->next;
	}
	return (cur);
}
