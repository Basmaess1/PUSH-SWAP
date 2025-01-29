/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bessabri <bessabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:18:02 by bessabri          #+#    #+#             */
/*   Updated: 2025/01/28 22:00:31 by bessabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	swap(stack_a, "sa");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b, "sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, NULL);
	swap(stack_b, NULL);
	ft_printf("ss\n");
}
