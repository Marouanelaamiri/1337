/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:35:46 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 16:32:03 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void rotate(t_stack **stack)
{
    t_stack *last_node;
    t_stack *first_node;

    if (!stack || !*stack || !(*stack)->next)
        return ; // if the stack is empty or has only one node, there's no need to rotate

    first_node = *stack; // The first node of the stack
    *stack = first_node->next; // Move the head to the next node
    (*stack)->prev = NULL; // Set the new head's previous pointer to NULL

    last_node = find_last(*stack); // Find the last node of the stack
    last_node->next = first_node; // Make the last node's next point to the first node
    first_node->prev = last_node; // Set the first node's previous pointer to the last node
    first_node->next = NULL; // Set the first node's next pointer to NULL (it's now the last node)
}

void ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
