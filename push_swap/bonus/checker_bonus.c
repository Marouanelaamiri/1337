/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:41:24 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 18:47:40 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	checker(char *line, t_stack **a, t_stack **b)
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
		display_errors(a);
}

void	ft_check_gnl(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!line)
			break ;
		checker(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

void	ft_answer(t_stack **a, t_stack **b)
{
	if (!(*b) && is_stack_sorted(*a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**str;

	if (argc < 2)
		return (0);
	str = NULL;
	a = NULL;
	b = NULL;
	if (argc == 2)
		str = split(argv[1], ' ');
	else 
		str = argv + 1;
	if (!str)
		return (1);
	init_stack_a(&a, str);
	if (argc == 2)
		free_split(str);
	
	if (!a || is_stack_sorted(a))
		return (free_stack(&a), 0);

	ft_check_gnl(&a, &b);
	ft_answer(&a, &b);
}
