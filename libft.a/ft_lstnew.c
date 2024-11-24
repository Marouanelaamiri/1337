/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:51:21 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/15 18:02:14 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
#include<stdlib.h>
#include<stdio.h>

int main()
{
	char value = 42;
	t_list *node = ft_lstnew(&value);// this points to the new list node

	char *holder = (char *)node->content;// holder is a readable way 
	//to access the int value stored in the list node
	
	printf("%c\n", *holder);// *derefeerencing give us the value 
		//stored at the memory adress, & would give us the adress of holder
	
}
int main()
{

}