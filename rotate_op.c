/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bessabri <bessabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:17:53 by bessabri          #+#    #+#             */
/*   Updated: 2025/01/28 22:02:01 by bessabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	rotate(stack_a, "ra");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b, "rb");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, NULL);
	rotate(stack_b, NULL);
	ft_printf("rr\n");
}
