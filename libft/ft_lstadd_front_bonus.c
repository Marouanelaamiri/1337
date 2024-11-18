/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:26:37 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/08 13:03:22 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*#include <stdio.h>
int main()
{
	t_list *node1 = ft_lstnew("Second node");
	t_list *node2 = ft_lstnew("Third node");

	node1->next = node2;
	
	t_list *new_node = ft_lstnew("First node");
	ft_lstadd_front(&node1, new_node);

	t_list *current = node1;

	while (current)
	{
		printf("Node content : %s\n", (char *)current->content);
		current = current->next;
	}
	free(node1);
	free(node2);
}*/