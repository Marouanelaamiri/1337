/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:33:50 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 13:33:51 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	find_target_for_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->data > b->data && current_a->data < best_match_index)
			{
				best_match_index = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	at_index(a);
	at_index(b);
	find_target_for_b(a, b);
}