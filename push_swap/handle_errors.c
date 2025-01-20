/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:01 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/20 13:26:08 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_errors(char *str)
{
	if (*str != '+' && *str != '-' && (*str < '0' || *str > '9'))
	{
		return (1);
	}
	if ((*str == '+' || *str == '-') && (str[1] < '0' || str[1] > '9'))
	{
		return (1);
	}
	str++;
	while (*str)
	{
		if (*str < '0' && *str > '9')
		{
			return (1);
		}
	str++;
	}
	return (0);
}

int	check_for_dup(t_stack_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next; 
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	write(1,"Error\n", 6);
	exit(1);
}
