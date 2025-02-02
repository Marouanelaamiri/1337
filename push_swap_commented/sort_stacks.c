/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:19:39 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/31 17:53:07 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack **a, t_stack **b) // this function sorts the stacks 
{
	int	len_a;

	len_a = len_of_stack(*a);
	if (len_a-- > 3 && !is_stack_sorted(*a)) // if the stack has more than 3 nodes and is not sorted
		pb(b, a); // we push the first node to stack b 
	if (len_a-- > 3 && !is_stack_sorted(*a)) // if the stack still has more than 3 nodes and is not sorted
		pb(b, a); // we push the second node to stack b
	while (len_a-- > 3 && !is_stack_sorted(*a)) // while the stack has more than 3 nodes and is not sorted 
	{
		init_nodes_a(*a, *b); // we initialize the nodes in stack a
		move_a_to_b(a, b); // we move the cheapest node from stack a to stack b
	}
	sort_three(a); // we sort the remaining 3 nodes in stack a
	while (*b) // while stack b is not empty
	{
		init_nodes_b(*a, *b); // we initialize the nodes in stack b
		move_b_to_a(a, b); // we move the node from stack b to stack a
	}
	at_index(*a); // we update the index of the nodes in stack a
	min_on_top(a); // we keep rotating the stack until the smallest number is on top
}
