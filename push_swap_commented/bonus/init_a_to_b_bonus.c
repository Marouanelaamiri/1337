/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:33:33 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 13:33:37 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	find_target_for_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->data < a->data && current_b->data > best_match_index)
			{
				best_match_index = current_b->data;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	at_index(a);
	at_index(b);
	find_target_for_a(a, b);
	cost_calcule_a(a, b);
	set_cheapest(a);
}