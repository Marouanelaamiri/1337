/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:21:33 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/07 12:41:32 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)//this functio search for a substring "needle"
																		// inside a large string haystack
{
	size_t	i;// itirate in haystack
	size_t	j;// itirate in needle
	char	*haystack1; 
	char	*needle1;

	i = 0;
	j = 0;
	haystack1 = (char *) haystack;// we cast haystack and needle for easier manipulation
	needle1 = (char *) needle;
	if (needle1[j] == '\0')// if needle is an empty string we return the haystack without iriration cuz we know its there .
		return (haystack1);
	while (haystack[i] && i < len)// dont check beyon haystack and stay within the len as well
	{
		while (haystack[i + j] && haystack[i + j] == needle[j] && i + j < len)// we keep looking when we are not at the end of haystack and we find a match and we are not past the len
		{
			j++;
			if (needle[j] == '\0')
				return (haystack1 + i);// return haystack at position i.
		}
		i++;	// if needle is not fully matched , move to the next postion 
		j = 0;	//and reset j so we itirate forn the begning of the new position
	}
	return (0);
}
/*#include <stdio.h>
#include <string.h>
int main()
{
	char	haystack[] = "looking for marouane in maroc malaga marwane";
	char	needle[] = "marouane";
	//printf("%s\n", ft_strnstr(haystack, needle, 0));
	printf("%s\n", strnstr(haystack, needle, 0));
}*/