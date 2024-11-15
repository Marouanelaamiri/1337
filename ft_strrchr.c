/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:55:46 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/11 10:33:22 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)//this functions goal is to find the last occurance of a char 'c'
										//in the string and retur a pointer to its position .
{
	size_t	i;
	char	ch;
	char	*ret;

	ch = (char) c; // we cast it to a char so we can compare it to chars in 's'.
	i = 0;
	ret = NULL;
	while (s[i])
	{
		if (s[i] == ch)
			ret = (char *) &s[i];// we continously updating ret so we keep track of thelast occurance of 'ch' or 'c'.
		i++;
	}
	if (ch == '\0')
		return ((char *) &s[i]);// case for null , we know every string ends with null so we have to return a pointer to the end of the string .
	else
		return (ret);
}
#include<string.h>
#include<stdio.h>
int main()
{
    // char	str[] = "hello eipeeeeepeeei";
    // char	ch = 'e';
	printf("%s\n" ,ft_strrchr("l\0\0l" ,'l'));
   printf("%s\n", strrchr("l\0\0l", 'l'));
}