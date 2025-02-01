/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:19:39 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/31 10:53:21 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = len_of_stack(*a);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !is_stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	at_index(*a);
	min_on_top(a);
}
