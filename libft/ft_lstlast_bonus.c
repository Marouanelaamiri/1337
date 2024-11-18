/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:37:12 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/08 13:25:47 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
/*#include <stdio.h>

int main()
{
	t_list *node1 = ft_lstnew("first node");
	t_list *node2 = ft_lstnew("second node");
	t_list *node3 = ft_lstnew("third node");

	node1->next = node2;
	node2->next = node3;

	t_list *last_node = ft_lst_last(NULL);
	if (last_node == NULL)
		return (1);
	printf("last node content : %s\n",(char *)last_node->content);

	free(node1);
	free(node2);
	free(node3);
}*/