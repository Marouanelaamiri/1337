/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:18:16 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/06 20:23:58 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))// this function applies a given function
															// to each character in str 's'
{
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

/*#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int mul(int a, int b)
{
	return a * b;
}

int main()
{
	printf("%d\n", add(10, 20)); //30
	printf("%d\n", mul(10, 20)); //200
}*/