/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bessabri <bessabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:19:08 by bessabri          #+#    #+#             */
/*   Updated: 2025/01/29 10:55:46 by bessabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, int *flag)
{
	int			signe;
	long		res;
	int			i;

	signe = 1;
	*flag = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			signe = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
		if (( signe *res > INT_MAX) || (signe *res < INT_MIN))
		{
			*flag = 0;
			return (0);
		}
	}
	return ((int)(res * signe));
}

int	is_valid_integer(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_stack		*i;
	t_stack		*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

t_stack	*handle_one_input(char *str)
{
	char				**res;
	t_stack_info		s;

	int (i), (flag);
	flag = 0;
	i = 0;
	init_stack_info(&s);
	res = ft_split(str, ' ');
	if (!res)
		return (NULL);
	while (res[i])
	{
		if (!is_valid_integer(res[i]))
			return (free_stack(s.stack), ft_free(res), NULL);
		s.new_node = ft_lstnew(ft_atoi(res[i++], &flag));
		if (!s.new_node || !flag)
			return (free_stack(s.stack), ft_free(res), NULL);
		if (!s.stack)
			s.stack = s.new_node;
		else
			s.current->next = s.new_node;
		s.current = s.new_node;
	}
	ft_free(res);
	return (s.stack);
}

t_stack	*handle_multiple_args(int ac, char **av)
{
	int					i;
	int					flag;
	t_stack_info		s;

	init_stack_info(&s);
	flag = 1;
	i = 1;
	while (i < ac)
	{
		if (!is_valid_integer(av[i]))
			return (free_stack(s.stack), NULL);
		s.new_node = ft_lstnew(ft_atoi(av[i], &flag));
		if (!s.new_node || !flag)
			return (free_stack(s.stack), NULL);
		if (!s.stack)
			s.stack = s.new_node;
		else
			s.current->next = s.new_node;
		s.current = s.new_node;
		i++;
	}
	return (s.stack);
}

// t_stack	*handle_one_input(char *str)
// {
// 	char		**res;

// 	int (i), (flag);
// 	t_stack (*stack), (*current), (*new_node);
// 	stack = NULL;
// 	current = NULL;
// 	flag = 0;
// 	i = 0;
// 	res = ft_split(str, ' ');
// 	if (!res)
// 		return (NULL);
// 	while (res[i])
// 	{
// 		if (!is_valid_integer(res[i]))
// 			return (free_stack(stack), ft_free(res), NULL);
// 		new_node = ft_lstnew(ft_atoi(res[i++], &flag));
// 		if (!new_node)
// 			return (free_stack(stack), ft_free(res), NULL);
// 		if (!stack)
// 			stack = new_node;
// 		else
// 			current->next = new_node;
// 		current = new_node;
// 	}
// 	return (ft_free(res), stack);
// }
