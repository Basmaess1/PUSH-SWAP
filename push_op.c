/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bessabri <bessabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:21:18 by bessabri          #+#    #+#             */
/*   Updated: 2025/01/28 22:04:05 by bessabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a, "pa");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b, "pb");
}
