/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:31:57 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/13 10:04:25 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		++i;
		lst = lst->next;
	}
	return (i);
}
#include <stdio.h>
int main()
{
	t_list *node1 = ft_lstnew("First node");

	ft_lstadd_back(&node1, ft_lstnew(ft_strdup("second node")));
	ft_lstadd_back(&node1, ft_lstnew(ft_strdup("THIRD node")));
	
	while (node1)
	{
		printf("|%s|", node1->content);
		node1 = node1->next;
	}

	// free(node1);
	// free(node2);
	// free(node3);
}