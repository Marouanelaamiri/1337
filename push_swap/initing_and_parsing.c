/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initing_and_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:31 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 21:41:12 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstadd_back(t_stack **lst, int n)
{
	t_stack	*new_node;
	t_stack	*last;

	if (!lst)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = n;
	new_node->cheapest = 0;
	if (!(*lst))
	{
		*lst = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = find_last(*lst);
		last->next = new_node;
		new_node->prev = last;
	}
}

void	init_stack_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (check_for_errors(argv[i]))
			display_errors(a);
		n = ft_atoi2(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			display_errors(a);
		if (check_for_dup(*a, (int)n))
			display_errors(a);
		ft_lstadd_back(a, (int)n);
		i++;
	}
}

t_stack	*look_for_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	get_ready_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_average)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_average)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
