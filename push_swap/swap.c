/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:36 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 21:59:24 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*old_head;
	t_stack	*new_head;

	if (!head || !(*head) || !(*head)->next)
		return ;
	old_head = *head;
	new_head = old_head->next;
	*head = new_head;
	old_head->next = new_head->next;
	if (new_head->next)
		new_head->next->prev = old_head;
	new_head->next = old_head;
	new_head->prev = NULL;
	old_head->prev = new_head;
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
