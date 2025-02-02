/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:31:10 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 21:20:50 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

typedef struct s_stack 
{
	int					data;
	int					index; 
	int					push_cost; 
	bool				above_average;
	bool				cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//Handle errors
int		check_for_errors(char *str_n); 
int		check_for_dup(t_stack *a);
void	free_stack(t_stack **stack);
void	display_errors(t_stack**a);
void	free_split(char **split_result);
void	ft_free_str(char **lst);

//Stack initiation
void	init_stack_a(t_stack **a, char **argv);
char	**split(char *s, char c);

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
int	is_stack_sorted(t_stack *stack_a);
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
t_stack	*ft_process(int argc, char **argv);
void	sort_stacks(t_stack **a, t_stack **b);//Turk algorithm

////helpers
long	ft_atoi2(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	*ft_free(char **arr, int count);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	put_str(char *str);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack	*lst_new(int content);
char	**ft_split(char const *s, char c);

//GNL 
char	*get_next_line(int fd);

//Sorting utils
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);

#endif