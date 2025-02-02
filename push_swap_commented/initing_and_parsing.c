/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initing_and_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:31 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/22 20:57:29 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstadd_back(t_stack **lst, int n) // this function adds a node to the end of a doubly linked list
{
	t_stack	*new_node;
	t_stack	*last;

	if (!lst)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;    // Set the next pointer to NULL
	new_node->data = n;        // Assign the integer value to the new node
	new_node->cheapest = 0;   // Set the cheapest flag to 0
	if (!(*lst))
	{
		*lst = new_node;      // If the list is empty, set the new node as the head
		new_node->prev = NULL; // Set the prev pointer to NULL
	}
	else
	{
		last = find_last(*lst); // Find the last node in the list
		last->next = new_node;  // Update the new node's prev pointer
		new_node->prev = last;   // Update the last node's next pointer
	}
}


void	init_stack_a(t_stack **a, char **argv) // this function start the stack by converting args from cmd to ints and appending them to the stack
{
	long	n;
	int		i;

	i = 0;
	while (argv[i]) // loop through the arguments
	{
		if (check_for_errors(argv[i])) // check for errors in the arguments
			display_errors(a);
		n = ft_atoi2(argv[i]); // convert the argument to an integer
		if (n > INT_MAX || n < INT_MIN) // check for overflow
			display_errors(a);
		if (check_for_dup(*a, (int)n)) // check for duplicates
			display_errors(a); 
		ft_lstadd_back(a, (int)n); // if all is good, append(add a node to the end) 	
		i++;
	}
}

t_stack	*look_for_cheapest(t_stack *stack) // this function looks for the node with the label cheapest and returns it
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack); // if the node has the label cheapest, return it
		stack = stack->next; // move to the next node
	}
	return (NULL); // if no node has the label cheapest, return NULL
}

void	get_ready_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node) // this function prepares the stack for pushing by rotating a node in the required stack , so it be in its favorable position
	{
		if (stack_name == 'a')
		{
			if (top_node->above_average) // if the node is above the median ra is used because the node is closer to the top
				ra(stack);
			else
				rra(stack); // else rra is used because the node is closer to the bottom 
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_average) // same applies here
				rb(stack);
			else
				rrb(stack);
		}	
	}
}