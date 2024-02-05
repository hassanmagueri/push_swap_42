/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:05:32 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/31 18:06:36 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stk_clear(t_stack **lst)
{
	t_stack	*cur;
	t_stack	*nxt;

	if (!lst)
		return ;
	cur = *lst;
	while (cur)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
	*lst = NULL;
}
