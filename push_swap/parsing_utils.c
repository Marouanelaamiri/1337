/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:01 by malaamir          #+#    #+#             */
/*   Updated: 2025/02/07 12:00:42 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_errors(char *str)
{
	int	has_digit;

	has_digit = 0;
	while (*str)
	{
		while (*str == ' ')
			str++; // Skip leading spaces

		if (*str == '+' || *str == '-')
		{
			str++;
			if (*str < '0' || *str > '9') // Ensure sign is followed by a digit
				return (1);
		}

		if (*str >= '0' && *str <= '9') // Valid number starts here
		{
			has_digit = 1;
			while (*str >= '0' && *str <= '9') // Move through number
				str++;
		}
		else if (*str != '\0') // If anything unexpected appears
		{
			return (1);
		}
	}
	return (has_digit ? 0 : 1); // Ensure at least one valid number exists
}


int	check_for_dup(t_stack *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->data == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	display_errors(t_stack **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}
