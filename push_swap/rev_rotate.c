/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:17 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/20 21:24:42 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
    t_stack_node *last; // store pointer to the last node
    t_stack_node *second_last; // store pointer to the node before the last

    if (!stack || !*stack || !(*stack)->next)
        return ; // if the stack is empty or has only one node, there's no need to rotate

    // Traverse to find the second-to-last and last nodes
    last = *stack; // we start from the head
    while (last->next)
    {
        second_last = last; // we keep updatig the second-last to the previous node
        last = last->next; // we keep updating the last node to the next node till we reach the NULL
    }

    // Disconnect the last node
    second_last->next = NULL; // now the node before the last node pointes to NULL / TLDR: the last node is now disconnected its gonna be the new head

    // Move the last node to the top
    last->next = *stack; // the last node now points to the head
    last->prev = NULL; // the last node's previous pointer is NULL <- <1> -> <2> -> <3> -> NULL
    (*stack)->prev = last; // the previous head's previous pointer pointes to the new head
    *stack = last; // the new head is now the previous last node
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);

		write(1,"rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);

	write (1,"rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	
	write(1,"rrr\n", 4);
}