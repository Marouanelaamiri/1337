/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:53:53 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/07 13:19:28 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)// this function 's goal is to remove unwanted chars from the beginning and the end of a string 

{
	unsigned int	maxlen;
	size_t			start;
	size_t			end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));// we used strdup cuz we need to allocate a place in memory for that empty string.
	start = 0;
	end = ft_strlen(s1) - 1;// so end points to the end of the string but excluding the null .
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	while (end > 0 && ft_strchr(set, s1[end]))
		end--;
	maxlen = (end - start + 1);// we need +1 to include the first char at start
	if (maxlen <= 0)
		return (ft_strdup(""));// if max len is 0 or less means that there isonly unwanted chars at that str so we return an empty clean str
	return (ft_substr(s1, start, maxlen));
}
//ft_strchr(set, s1[start]): This checks if the character at s1[start] is in the set of characters set. ft_strchr 
//returns a pointer to the first occurrence of the character in set or NULL if it’s not found.

// ft_strchr(set, s1[end]): This checks if s1[end] is in the set of unwanted characters.
// If s1[end] is in the set, we move end backwards to the previous character.
// We continue this loop until we find a character that’s not in the set or until end becomes negative.
#include <stdio.h>
int main()
{
    // char *str = NULL;
    // char *set = "";

    printf("%s\n", ft_strtrim("", ""));
}