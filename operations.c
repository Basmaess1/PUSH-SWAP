/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bessabri <bessabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:19:17 by bessabri          #+#    #+#             */
/*   Updated: 2025/01/28 23:36:22 by bessabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char *op)
{
	t_stack		*first;
	t_stack		*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (op)
		ft_printf("%s\n", op);
}

void	rotate(t_stack **head, char *op)
{
	t_stack		*tmp;
	t_stack		*last;

	tmp = *head;
	*head = tmp->next;
	tmp->next = NULL;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = tmp;
	if (op)
		ft_printf("%s\n", op);
}

void	reverse_rotate(t_stack **head, char *op)
{
	t_stack		*tmp;
	t_stack		*last;

	tmp = NULL;
	last = *head;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	tmp->next = NULL;
	last->next = *head;
	*head = last;
	if (op)
		ft_printf("%s\n", op);
}

void	push(t_stack **src, t_stack **dest, char *op)
{
	t_stack		*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	if (op)
		ft_printf("%s\n", op);
}
