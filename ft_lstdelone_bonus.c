/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:47:44 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/14 16:57:18 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del (lst->content);
	free (lst);
}
void	delet(void *content)
{
	free(content);
}
int main()
{
	t_list *node1 = ft_lstnew(ft_strdup("NODE 1"));
	t_list *node2 = ft_lstnew(ft_strdup("NODE 2"));
	t_list *node3 = ft_lstnew(ft_strdup("NODE 3"));

	node1->next = node2;
	node2->next = node3;
	
	t_list *current = node1;
	while(current)
	{
		printf("before %s\n", current->content);
		current = current->next;
	} 
	ft_lstdelone(node2, delet);
	current = node1;
	node1->next = node3;
	while(current)
	{
		printf("after %s\n", current->content);
		printf("after %p\n", current->content);
		current = current->next;
	} 
	
}