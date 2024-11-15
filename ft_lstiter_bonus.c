/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:27:52 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/14 22:10:02 by malaamir         ###   ########.fr       */
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
	int *res = (int *)content;
	*res *= 2;
}
int main ()
{
	int i  = 10;
	int i2 = 20;
	int i3 = 30;
	t_list *node1 = ft_lstnew(&i);
	t_list *node2 = ft_lstnew(&i2);
	t_list *node3 = ft_lstnew(&i3);
	node1->next = node2;
	node2->next = node3;
	
	t_list *current = node1;
	while(current)
	{
		int *res = current->content; 
		printf("before %d\n", *res);
		current = current->next;

	}

	current = node1;
	ft_lstiter(node1, add2);
	while (current)
	{
		int *res = current->content;
		printf("after %d\n", *res);
		current = current->next;
	}
}