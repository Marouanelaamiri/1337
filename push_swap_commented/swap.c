/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:36 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/22 21:02:47 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	
    t_stack *old_head;
    t_stack *new_head;

    if (!head || !(*head) || !(*head)->next)
        return; //if the stack is empty or has only one node, there is no need to swap
	
    old_head = *head; // we set this variable to keep track of the old head , he is the head rn
    new_head = old_head->next; // the new head is gonna be the node next to the head 
    *head = new_head; // we set it here
    old_head->next = new_head->next; // and we set the next node of the old head to the next node of the new head so we skip the new head
    if (new_head->next)
        new_head->next->prev = old_head; // if the new head has a next node we set the previous node of the next node to the old head
    new_head->next = old_head; // and we set the next node of the new head to the old head
    new_head->prev = NULL;	// and we set the previous node of the new head to NULL
    old_head->prev = new_head; // and we set the previous node of the old head to the new head
}

void	sa(t_stack	**a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
