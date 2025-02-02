/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:34:35 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 21:20:31 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	check_for_dup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->data == tmp->data)
				return (1);
			tmp = tmp->next;
		}
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
	write(1,"Error\n", 6);
	exit(1);
}
