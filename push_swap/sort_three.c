/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:26 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 21:56:40 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*big_node;

	big_node = find_max(*a);
	if (big_node == *a)
		ra(a);
	else if ((*a)->next == big_node)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
