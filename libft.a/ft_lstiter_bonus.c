/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:27:52 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/15 17:39:20 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
void	add2(void *content)
{
	char *ptr = (char *)content;
	while (*ptr)
	{
		*ptr = * ptr + 32;
		ptr++;
	}
}
int main ()
{

	t_list *node1 = ft_lstnew(ft_strdup("HELLO"));
	t_list *node2 = ft_lstnew(ft_strdup("WORLD"));
	t_list *node3 = ft_lstnew(ft_strdup("LOL"));
	node1->next = node2;
	node2->next = node3;
	
	t_list *current = node1;
	while(current)
	{		
			char *res = current->content; 
			printf("before %p\n", res);
			current = current->next;
	}
	current = node1;
	ft_lstiter(node1, add2);
	while (current)
	{
		char *res = current->content;
		printf("after %p\n", res);
		current = current->next;
	}
}
