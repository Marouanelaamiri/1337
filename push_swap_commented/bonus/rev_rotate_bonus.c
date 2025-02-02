/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:35:35 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 16:32:15 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rev_rotate(t_stack **stack)
{
    t_stack *last; // store pointer to the last node
    t_stack *second_last; // store pointer to the node before the last

    if (!stack || !*stack || !(*stack)->next)
        return ; // if the stack is empty or has only one node, there's no need to rotate

    // Traverse to find the second-to-last and last nodes
    last = *stack; // we start from the head
    while (last->next)
    {
        last = last->next; // we keep updating the last node to the next node till we reach the NULL
        second_last = last; // we keep updatig the second-last to the previous node
    }

    // Disconnect the last node
    second_last->next = NULL; // now the node before the last node pointes to NULL / TLDR: the last node is now disconnected its gonna be the new head <- <1> -> <2> -> <3> -> NULL  | <4> disconnected |

    // Move the last node to the top
    last->next = *stack; // we know that the last node is now the head , and its next is the old head so we update it accordinly <- <4> -> <1> -> <2> -> <3> -> NULL (<1> is the old head) was in the *stack
    last->prev = NULL; // the last node's previous pointer is NULL <- <1> -> <2> -> <3> -> NULL
    (*stack)->prev = last; // the previous head's previous pointer pointes to the new head
    *stack = last; // we connect the new head to the stack ; 
}

void	rra(t_stack **a)
{
	rev_rotate(a);
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
}