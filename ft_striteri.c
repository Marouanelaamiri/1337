/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:18:16 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/12 14:16:09 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))// this function applies a given function
															// to each character in str 's'
{
	if (s == NULL || f == NULL)
		return ;
		
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// The function takes two parameters:
// s: a pointer to the string on which we want to perform operations.
// f: a function pointer that takes two arguments:
// unsigned int: the index of the current character.
// char*: a pointer to the character itself.
// Using char* allows f to modify the character at its memory location in the string s,
// so ft_striteri can apply transformations directly to the original string 
//  rather than to copies of its characters

// #include <stdio.h>

// void	to_upper(unsigned int i, char *c)
// {
	
// 	if (*c <= 'z' && *c >= 'a')
// 		*c = *c - 32;
// }

// int main()
// {
// 	char *str = "hello";
// 	ft_striteri(str, to_upper);
// 	printf("%s\n", str);
// }