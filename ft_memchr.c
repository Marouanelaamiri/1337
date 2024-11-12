/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:35:05 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/06 11:43:28 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)//search in a block of memory for a spesefic char 
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
	unsigned char str[] = "banana";
	unsigned char ch = 'a';
	printf("%c , %s\n", ch, ft_memchr(str , ch ,6));
	printf("%c, %s\n", ch , memchr(str ,ch , 6));
}*/
//Imagine you’re going through each box one by one. If you open a box and find
//the key you’re looking for, you immediately stop searching and return the
//location of that box. You’ve found what you need, so no need to keep looking!