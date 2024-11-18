/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:10:03 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/13 10:07:02 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current;
		current = current->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
void	del_content(void* content)
{
	free(content);
}
#include <stdio.h>

int main()
{
	t_list	*node1 = ft_lstnew(ft_strdup("NODE 1"));
	t_list	*node2 = ft_lstnew(ft_strdup("NODE 2"));
	t_list	*node3 = ft_lstnew(ft_strdup("NODE 3"));

	node1->next = node2;
	node2->next = node3;
	node3->next =NULL;

	t_list *current = node1;
	while(current)
	{
		printf("nodes before clearing :%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&node1, del_content);

	if (node1 == NULL)
		printf("List is cleard GG!!\n");
}