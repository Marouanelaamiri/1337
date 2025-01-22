/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:41:46 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/22 20:37:03 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack_node 
{
	int					nbr;
	int					index; 
	int					push_cost; 
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;
//***Handle errors
int				check_for_errors(char *str_n); 
int				check_for_dup(t_stack_node *a, int nbr);
void			free_stack(t_stack_node **stack);
void			display_errors(t_stack_node **a);

//***Stack initiation
void			init_stack_a(t_stack_node **a, char **argv);
char			**split(char *s, char c);

//***Nodes initiation
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			at_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*look_for_cheapest(t_stack_node *stack);
void			get_ready_for_push(t_stack_node **s, t_stack_node *n, char c);
void			cost_calcule_a(t_stack_node *a, t_stack_node *b);
//***Stack utils
int				len_of_stack(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			is_stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

//***Commands
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

//***Algorithm
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b); //Turk algorithm

////  helpers  /////
long	ft_atoi2(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	*ft_free(char **arr, int count);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	put_str(char *str);

/////// Sorting utils ///////
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void	move_a_to_b(t_stack_node **a, t_stack_node **b);
void	move_b_to_a(t_stack_node **a, t_stack_node **b);
void	min_on_top(t_stack_node **a);

#endif