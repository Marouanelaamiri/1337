/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:51:21 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/08 11:20:40 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*#include<stdlib.h>
#include<stdio.h>

int main()
{	
	t_list *new_node = ft_lstnew((void *)"THIS IS A NEW NODE");

	if (new_node == NULL)
		return (1);
	printf("Node content : %s\n", (char *)new_node->content);

	free(new_node);
	// The -> operator is a shorthand for dereferencing
	// the pointer and then accessing the member.
}*/