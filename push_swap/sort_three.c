/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:26 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/20 15:41:11 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*big_node;

	big_node = find_max(*a); // we find the biggest node in the stack 
	if (big_node == *a) // if the biggest node is the first node we rotate the stack
		ra(a);
	else if ((*a)->next == big_node) // if the biggest node is the second node we reverse rotate the stack
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr) // if the first node is bigger than the second node we swap them
		sa(a);
}

