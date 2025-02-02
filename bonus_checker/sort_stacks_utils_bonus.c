/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:35:58 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 13:36:00 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node) // rotate both stacks
{
	while (*b != cheapest_node->target && *a != cheapest_node) // while the target node is not on top of stack b and the cheapest node is not on top of stack a
		rr(a, b);
	at_index(*a);
	at_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node) // reverse rotate both stacks
{
	while (*b != cheapest_node->target && *a != cheapest_node) // while the target node is not on top of stack b and the cheapest node is not on top of stack a
		rrr(a, b);
	at_index(*a);
	at_index(*b);
}

void	move_a_to_b(t_stack **a, t_stack **b) // move the cheapest node from stack a to stack b
{
	t_stack	*cheapest_node;

	cheapest_node = look_for_cheapest(*a); // get the cheapest node in stack a
	if (cheapest_node->above_average && cheapest_node->target->above_average)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_average) && !(cheapest_node->target->above_average))
		rev_rotate_both(a, b, cheapest_node);
	get_ready_for_push(a, cheapest_node, 'a'); 
	get_ready_for_push(b, cheapest_node->target, 'b');
	pb(b, a);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	get_ready_for_push(a, (*b)->target, 'a');
	pa(a, b); 
}
void	min_on_top(t_stack **a) // we keep rotating the stack until the smallest number is on top
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->above_average)
			ra(a);
		else
			rra(a);
	}
}
