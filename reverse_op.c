/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bessabri <bessabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:18:14 by bessabri          #+#    #+#             */
/*   Updated: 2025/01/28 22:05:45 by bessabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a, "rra");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b, "rrb");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, NULL);
	reverse_rotate(stack_b, NULL);
	ft_printf("rrr\n");
}
