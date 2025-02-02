/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:07:24 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/22 20:56:45 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_calcule_a(t_stack *a, t_stack *b)// this function calculates the cost of pushing a node from stack a to stack b
{
	int	len_a;
	int	len_b;

	len_a = len_of_stack(a);
	len_b = len_of_stack(b);
	while (a)
	{
		a->push_cost = a->index;// the cost of pushing a node from stack a to stack b is the index of the node in stack a
		if (!(a->above_average))
			a->push_cost = len_a - (a->index);// if the node is below the median, the cost is the length of stack a minus the index of the node
		if (a->target->above_average)
			a->push_cost += a->target->index;// if the target node is above the median, we add the index of the target node
		else
			a->push_cost += len_b - (a->target->index);// if the target node is below the median, we add the length of stack b minus the index of the target node
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
	median = len_of_stack(stack) / 2; // we calculate the median of the stack
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_average = true; // if the index of the node is less than the median, we set the above_median flag to true
		else
			stack->above_average = false;// if the index of the node is greater than the median, we set the above_median flag to false
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
	cheapest_value = LONG_MAX; // we set the cheapest value to the maximum value of a long 
	while (stack)
	{
		if (stack->push_cost < cheapest_value) // we loop through the stack and compare the push cost of each node with the cheapest value
		{
			cheapest_value = stack->push_cost; // if the push cost of the node is less than the cheapest value, we update the cheapest value
			cheapest_node = stack; // we update the cheapest node
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true; // we set the cheapest flag of the cheapest node to true
}