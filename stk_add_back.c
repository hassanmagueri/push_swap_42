/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 05:44:16 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/23 23:47:49 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stk_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*lstlast;

	if (!lst)
		return ;
	lstlast = *lst;
	if (!lstlast)
	{
		*lst = new;
		return ;
	}
	stk_last(*lst)->next = new;
}
