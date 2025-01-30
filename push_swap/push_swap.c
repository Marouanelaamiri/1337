/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:10 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 21:45:52 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**handle_arguments(int argc, char **argv)
{
	char	**split_result;

	split_result = NULL;
	if (argc == 2)
	{
		split_result = split(argv[1], ' ');
		if (!split_result)
			return (NULL);
		argv = split_result;
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_result;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	a = NULL;
	b = NULL;
	split_result = handle_arguments(argc, argv);
	if (!split_result)
		return (1);
	init_stack_a(&a, split_result + 1);
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
