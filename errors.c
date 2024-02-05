/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:09:50 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/03 21:41:02 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	print_error_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_print_error_exit(char *str)
{
	free(str);
	print_error_exit();
}
