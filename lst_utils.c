/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bessabri <bessabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:56:00 by bessabri          #+#    #+#             */
/*   Updated: 2025/01/29 10:49:28 by bessabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*ft_lstnew(int value)
{
	t_stack		*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->value = value;
	newnode->next = NULL;
	return (newnode);
}

void	free_stack(t_stack *stack)
{
	t_stack		*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	init_stack_info(t_stack_info *s)
{
	s->stack = NULL;
	s->current = NULL;
}
