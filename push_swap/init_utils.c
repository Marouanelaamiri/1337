/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:07:24 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 21:39:32 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_calcule_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = len_of_stack(a);
	len_b = len_of_stack(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_average))
			a->push_cost = len_a - (a->index);
		if (a->target->above_average)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		a = a->next;
	}
}

void	at_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = len_of_stack(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_average = true;
		else
			stack->above_average = false;
		stack = stack->next;
		++i;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
