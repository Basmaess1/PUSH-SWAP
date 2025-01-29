/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortalgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bessabri <bessabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:43:51 by bessabri          #+#    #+#             */
/*   Updated: 2025/01/29 10:26:29 by bessabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_rotation(t_stack **stack, int positions, char stack_name,
	int reverse)
{
	while (positions--)
	{
		if (reverse)
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
		else
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
}

void	rotate_optimal(t_stack **stack, int target, char stack_name)
{
	t_stack		*current;
	int			pos;
	int			size;

	pos = 0;
	current = *stack;
	size = ft_lstsize(*stack);
	while (current && current->value != target)
	{
		pos++;
		current = current->next;
	}
	if (pos <= size / 2)
		perform_rotation(stack, pos, stack_name, 0);
	else
		perform_rotation(stack, size - pos, stack_name, 1);
}

int	get_chunk_size(int size, int min, int max)
{
	if (size <= 100)
		return ((max - min) / 4);
	return ((max - min) / 8);
}

void	update_chunk_bounds(int *start, int *end, int chunk_size, int max)
{
	*start = *end + 1;
	*end = *start + chunk_size;
	if (*end > max)
		*end = max;
}

/*static void	process_chunks(t_stack **stack_a, t_stack **stack_b, 
	int min, int max)
{
	int	chunk_size;
	int	chunk_start;
	int	target;
	int	chunk_end;
	int	size;

	size = ft_lstsize(*stack_a);
	chunk_size = (size <= 100) ? (max - min) / 4 : (max - min) / 8;
	chunk_start = min;
	chunk_end = chunk_start + chunk_size;
	while (*stack_a && chunk_start <= max)
	{
		target = find_closest_in_range(*stack_a, chunk_start, chunk_end);
		if (target >= chunk_start && target <= chunk_end)
		{
			rotate_optimal(stack_a, target, 'a');
			pb(stack_a, stack_b);
		}
		else
		{
			chunk_start = chunk_end + 1;
			chunk_end = chunk_start + chunk_size;
			if (chunk_end > max)
				chunk_end = max;
		}
	}
}*/
