/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:10 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/22 20:58:07 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_split(char **split_result)
{
	int i = 0;

	if (!split_result)
		return;

	while (split_result[i])
	{
		free(split_result[i]);
		i++;
	}
	free(split_result);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char			**split_result;

	a = NULL;
	b = NULL;
	split_result = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		split_result = split(argv[1], ' ');
		if (!split_result)
			return (1);
		argv = split_result;
	}
	init_stack_a(&a, argv + 1);
	if (!is_stack_sorted(a))
	{
		if (len_of_stack(a) == 2)
			sa(&a);
		else if (len_of_stack(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);        
	free_split(split_result);
	return (0);
}

