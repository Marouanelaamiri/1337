/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:17 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/20 15:00:05 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack_node **a)
{
    if (!a || !*a || !(*a)->next)
        return ;// if the stack is empty or has only one node, there is no need to rotate
    while ((*a)->next) // we loop through the stack until we reach the last node
        *a = (*a)->next;
  
        write(1, "rra\n", 4);
}

void rrb(t_stack_node **b)
{
    if (!b || !*b || !(*b)->next)
        return;
    while ((*b)->next)
        *b = (*b)->next;

        write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rra(a);
	rrb(b);
	
		write(1, "rrr\n", 4);
}
