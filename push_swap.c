/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bessabri <bessabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:45:36 by bessabri          #+#    #+#             */
/*   Updated: 2025/01/29 11:05:24 by bessabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_closest_in_range(t_stack *stack, int start, int end)
{
	t_stack		*current;
	int			closest;
	int			min_distance;
	int			pos;

	current = stack;
	closest = current->value;
	min_distance = ft_lstsize(stack);
	pos = 0;
	while (current)
	{
		if (current->value >= start && current->value <= end)
		{
			if (pos < min_distance)
			{
				min_distance = pos;
				closest = current->value;
			}
		}
		pos++;
		current = current->next;
	}
	return (closest);
}

void	process_chunks(t_stack **stack_a, t_stack **stack_b,
	int min, int max)
{
	int	chunk_size;
	int	chunk_start;
	int	target;
	int	chunk_end;

	chunk_size = get_chunk_size(ft_lstsize(*stack_a), min, max);
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
			update_chunk_bounds(&chunk_start, &chunk_end, chunk_size, max);
	}
}

void	perform_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 3)
	{
		handle_small_size(stack_a, size);
		return ;
	}
	process_chunks(stack_a, stack_b,
		get_min(*stack_a), get_max(*stack_a));
	while (*stack_b)
	{
		rotate_optimal(stack_b, get_max(*stack_b), 'b');
		pa(stack_b, stack_a);
	}
}

t_stack	*parse_input(int ac, char **av)
{
	t_stack		*stack;

	if (ac < 2)
		ft_error();
	if (ac == 2)
		stack = handle_one_input(av[1]);
	else
		stack = handle_multiple_args(ac, av);
	if (stack && has_duplicates(stack))
	{
		free_stack(stack);
		return (NULL);
	}
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = parse_input(ac, av);
	if (!stack_a)
	{
		ft_error();
		return (1);
	}
	perform_sort(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

// void print_stack(const char *name, t_stack *stack)
// {
//     printf("%s: ", name);
//     while (stack)
//     {
//         printf("%d ", stack->value);
//         stack = stack->next;
//     }
//     printf("\n");
// }