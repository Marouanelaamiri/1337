/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:02:19 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/07 11:32:18 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))// same as striteri , but this function does not modify directly
																// the string instead it create another string and does the modification on it 
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str = malloc((ft_strlen(s) + 1));// and ofc it have to allocate memory for this new str 
	if (str == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
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