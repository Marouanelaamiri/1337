/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:19:53 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/15 18:37:19 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)// this function locate the first occurence of a char 'c'
										// and it return a pointer to that location
{
	size_t	i;
	char	ch;

	ch = (char) c;// we casted int c to type char because we are working inside of a string 
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *) &s[i]); // if we found the ch we return a "pointer to that position "
		i++;
	}
	if (s[i] == ch)
		return ((char *)&s[i]);// protection case if the ch we are looking for is NULL
	else
		return (NULL);
}
// #include<string.h>
// #include<stdio.h>
// int main()
// {
// 	char	str[] = "hello iooeeeepppp";
// 	char	ch = '\0';
// 	printf("char '%c' found at : %s\n",ch, ft_strchr(str, ch));
// 	printf("char '%c'  found at : %s\n", ch, strchr(str, ch));
// }
