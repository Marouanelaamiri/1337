/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:44:49 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/07 14:08:51 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)// this function extract a sub string from the str it start at a giving position
																// at a giving position till len
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		tmp = malloc(1);
		if (tmp == NULL)
			return (NULL);
		tmp[0] = '\0';
		return (tmp);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	tmp = ft_calloc((len + 1), sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (i < len)
	{
		tmp[i] = s[start + i];
		i++;
	}
	return (tmp);
}
// If the start index is greater than or equal to the length of the string s, it means the starting point is beyond the end of the string,
//  so there's no valid substring to extract.

// In this case, we allocate a small memory block to hold an empty string ('\0') and return it.

// Why allocate 1 byte? We allocate just enough memory to hold an empty string "\0", 
// which signals that the substring is empty.

/*#include <stdio.h>
int main()
{
	// Edge case 0: ur come
	printf("%s\n", ft_substr("Bonjour comment ca va ?", 5,8));
	// Edge case 1: NULL string
    printf("%s\n", ft_substr(NULL, 0, 5)); // Expected: (null)

    // Edge case 2: Start index greater than string length
    printf("%s\n", ft_substr("Hello", 10, 5)); // Expected: ""

    // Edge case 3: Start index equal to string length
    printf("%s\n", ft_substr("Hello", 5, 5)); // Expected: ""

    // Edge case 4: Length is zero
    printf("%s\n", ft_substr("Hello", 1, 0)); // Expected: ""

    // Edge case 5: Length greater than remaining string length
    printf("%s\n", ft_substr("Hello", 1, 10)); // Expected: "ello"

    // Edge case 6: Start index is zero
    printf("%s\n", ft_substr("Hello", 0, 5)); // Expected: "Hello"

    // Edge case 7: Start index is in the middle of the string
    printf("%s\n", ft_substr("Hello World", 6, 5)); // Expected: "World"

    // Edge case 8: Length is exactly the remaining length from start
    printf("%s\n", ft_substr("Hello World", 6, 5)); // Expected: "World"

    // Edge case 9: Length is one
    printf("%s\n", ft_substr("Hello", 1, 1)); // Expected: "e"
	//
	printf("%s\n", ft_substr("", 5, 0));
}*/