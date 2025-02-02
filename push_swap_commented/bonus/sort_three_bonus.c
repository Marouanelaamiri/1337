/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:36:26 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 13:36:27 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sort_three(t_stack **a)
{
	t_stack	*big_node;

	big_node = find_max(*a); // we find the biggest node in the stack 
	if (big_node == *a) // if the biggest node is the first node we rotate the stack
		ra(a);
	else if ((*a)->next == big_node) // if the biggest node is the second node we reverse rotate the stack
		rra(a);
	if ((*a)->data > (*a)->next->data) // if the first node is bigger than the second node we swap them
		sa(a);
}

