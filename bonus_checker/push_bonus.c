/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:35:19 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 17:18:07 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	
	if (!*b) // if stack b is empty we return
		return ;
	tmp = (*b)->next; // we set the tmp to the next node of the stack b , so we can keep track of the next node
	(*b)->next = *a; // we set the next node of the stack b to the stack a so we dont lose connection on the stack a
	*a = *b; // we set the stack a to the stack b
	*b = tmp; // we set the stack b to the tmp
	if (*b)
		(*b)->prev = NULL; // if the stack b is not empty we set the previous node of the stack b to NULL
	if (*a)
		(*a)->prev = NULL; // if the stack a is not empty we set the previous node of the stack a to NULL
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	if (*a)
		(*a)->prev = NULL;
	if (*b)
		(*b)->prev = NULL;
}