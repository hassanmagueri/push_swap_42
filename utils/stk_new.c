/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:59:42 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/31 16:44:22 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stk_new(int nbr, int index)
{
	t_stack	*stk;

	stk = malloc(sizeof(t_stack));
	if (!stk)
		return (NULL);
	stk->nbr = nbr;
	stk->index = index;
	stk->next = NULL;
	return (stk);
}
