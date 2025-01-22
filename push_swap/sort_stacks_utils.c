/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:23 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/22 18:29:27 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node) // rotate both stacks
{
	while (*b != cheapest_node->target_node && *a != cheapest_node) // while the target node is not on top of stack b and the cheapest node is not on top of stack a
		rr(a, b);
	at_index(*a);
	at_index(*b);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node) // reverse rotate both stacks
{
	while (*b != cheapest_node->target_node && *a != cheapest_node) // while the target node is not on top of stack b and the cheapest node is not on top of stack a
		rrr(a, b);
	at_index(*a);
	at_index(*b);
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b) // move the cheapest node from stack a to stack b
{
	t_stack_node	*cheapest_node;

	cheapest_node = look_for_cheapest(*a); // get the cheapest node in stack a
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	get_ready_for_push(a, cheapest_node, 'a'); 
	get_ready_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	get_ready_for_push(a, (*b)->target_node, 'a');
	pa(a, b); 
}
void	min_on_top(t_stack_node **a) // we keep rotating the stack until the smallest number is on top
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
