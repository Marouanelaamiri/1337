/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:10 by malaamir          #+#    #+#             */
/*   Updated: 2025/02/07 12:20:52 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_args(int argc, char **argv)
{
	int		i;
	char	*result;
	char	*temp;
	char	*new_str;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		temp = result;
		new_str = ft_strjoin(temp, " ");
		free(temp);
		if (!new_str)
			return (NULL);
		temp = new_str;
		new_str = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!new_str)
			return (NULL);
		result = new_str;
		i++;
	}
	return (result);
}

int	handle_args(int argc, char **argv, t_stack **a)
{
	char	*joined_args;
	char	**split_args;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	joined_args = join_args(argc, argv);
	if (!joined_args)
		return (write(2, "Error\n", 6), 1);
	split_args = ft_split(joined_args, ' ');
	free(joined_args);
	if (!split_args)
		return (write(2, "Error\n", 6), 1);
	init_stack_a(a, split_args);
	free_split(split_args);
	return (0);
}

void	sort_stack_if_needed(t_stack **a, t_stack **b)
{
	if (!is_stack_sorted(*a))
	{
		if (len_of_stack(*a) == 2)
			sa(a);
		else if (len_of_stack(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (handle_args(argc, argv, &a))
		return (1);
	sort_stack_if_needed(&a, &b);
	free_stack(&a);
	return (0);
}
