/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:23 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 21:55:44 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rr(a, b);
	at_index(*a);
	at_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rrr(a, b);
	at_index(*a);
	at_index(*b);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = look_for_cheapest(*a);
	if (cheapest_node->above_average && cheapest_node->target->above_average)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_average)
		&& !(cheapest_node->target->above_average))
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

void	min_on_top(t_stack **a)
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->above_average)
			ra(a);
		else
			rra(a);
	}
}
