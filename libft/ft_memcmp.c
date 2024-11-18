/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:31:30 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/09 11:58:26 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)// compare a memory block byte by byte and returns the diffrence as int
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;// we type cast strs so we can acces memory blocks byte by byte
	str2 = (unsigned char *) s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
//if we didnt find any diffrence we return 0 //both strs are the same//
/*#include<stdio.h>
#include<string.h>
int main()
{
	char	s1[] = "hello";
	unsigned char	s2[] = "hello";
	printf("%d\n", ft_memcmp(s1, s2, 10));
   	printf("%d\n", memcmp(s1, s2, 10));
}*/