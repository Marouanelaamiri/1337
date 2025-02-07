/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:41:46 by malaamir          #+#    #+#             */
/*   Updated: 2025/02/07 11:33:44 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int					data;
	int					index;
	int					push_cost;
	bool				above_average;
	bool				cheapest;
	struct s_stack		*target;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

//Handle errors
int		check_for_errors(char *str_n);
int		check_for_dup(t_stack *a, int nbr);
void	free_stack(t_stack **stack);
void	display_errors(t_stack**a);

//Stack initiation
void	init_stack_a(t_stack **a, char **argv);

//Nodes initiation
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	at_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
t_stack	*look_for_cheapest(t_stack *stack);
void	get_ready_for_push(t_stack **s, t_stack *n, char c);
void	cost_calcule_a(t_stack *a, t_stack *b);

//Stack utils
int		len_of_stack(t_stack *stack);
t_stack	*find_last(t_stack *stack);
bool	is_stack_sorted(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);

//Operations
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

//Algorithm
void	sort_three(t_stack **a);
void	sort_stacks(t_stack **a, t_stack **b);//Turk algorithm

//helpers
long	ft_atoi2(const char *str);
void	free_split(char **split_result);
char	**ft_split(char *s, char c);

//Sorting utils
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);

#endif