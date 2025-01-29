/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bessabri <bessabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:18:55 by bessabri          #+#    #+#             */
/*   Updated: 2025/01/29 11:06:58 by bessabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int					value;
	struct s_stack		*next;

}t_stack;
typedef struct s_stack_info
{
	t_stack	*stack;
	t_stack	*current;
	t_stack	*new_node;
}t_stack_info;

//lst utils
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstnew(int value);
void	free_stack(t_stack *stack);
void	init_stack_info(t_stack_info *s);

//operations
void	swap(t_stack **stack, char *op);
void	rotate(t_stack **head, char *op);
void	reverse_rotate(t_stack	**head, char	*op);
void	push(t_stack **src, t_stack **dest, char *op);

//actions
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);

//check_errors
int		is_valid_integer(const char *str);
int		ft_atoi(const char *str, int *flag);
int		has_duplicates(t_stack *stack);
void	ft_error(void);
t_stack	*handle_multiple_args(int ac, char **av);
t_stack	*handle_one_input(char *str);
t_stack	*parse_input(int ac, char **av);

//sort_util1
void	sort_three_elements(t_stack **stack_a);
void	handle_two_elements(t_stack **stack_a);
void	handle_small_size(t_stack **stack_a, int size);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		find_closest_in_range(t_stack *stack, int start, int end);
// void print_stack(const char *name, t_stack *stack);
void	update_chunk_bounds(int *start, int *end, int chunk_size, int max);
int		get_chunk_size(int size, int min, int max);
//sortalgo
void	perform_sort(t_stack **stack_a, t_stack **stack_b);
void	process_chunks(t_stack **stack_a, t_stack **stack_b, int min, int max);
void	rotate_optimal(t_stack **stack, int target, char stack_name);
//split and utils
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	**ft_free(char **ptr);
size_t	ft_strlen(const char	*s);
#endif
