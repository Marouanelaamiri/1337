/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:41:24 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 21:22:53 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*checker(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b);
	else
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return(get_next_line(0));
}
void	checker_sub(t_stack **a, t_stack **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = checker(a, b, line);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!is_stack_sorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}
int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	char	*line;
	
	b = NULL;
	a = ft_process(ac, av);
	if (!a || check_for_dup(a))
		display_errors(&a);
	line = get_next_line(0);
	if (!line && !is_stack_sorted(a))
		write(1, "KO\n", 3);
	else if (!line && is_stack_sorted(a))
		write(1, "OK\n", 3);
	else
		checker_sub(&a, &b, line);
	free_stack(&a);
	free_stack(&b);
	return (0);
}