/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:33:09 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/15 18:59:45 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (arr[i])// if there is something in this slot where i is has been alocated 
			free(arr[i]); // free it
		i++;
	}
	free(arr);//free the entire arr
	return (NULL);// if something wrong happend return NULL
}

static size_t	get_len(const char *s, char c)
{
	if (ft_strchr(s, c))// if the char 'c' found return 
		return (ft_strchr(s, c) - s);// the distance of 'c' from the start
	return (ft_strlen(s));// else return the full lenght of str
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	if (!s[i]) // if str is empty return 0
		return (0);
	while (s[i])
	{
		if (s[i] == c) // if we encounter a delimiter skip it
			i++;
		else
		{
			count++;// found a word incrment count
			while (s[i] != c && s[i])// move past the current word keep going till u find a delimiter and get out of the loop
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	len;
	size_t	i;

	if (s == NULL)// protection case , if the input is NULL return NULL
		return (NULL);
	i = 0;
	arr = ft_calloc((ft_countword(s, c) + 1), sizeof(char *));
	if (arr == NULL)// if allocation fails return NULL
		return (NULL);
	while (*s)
	{
		while (*s == c)// skip over delimetrs at the start
			s++;
		if (*s)
		{
			len = get_len(s, c);// get the len of the next word
			arr[i] = ft_substr(s, 0, len);// jbddd lia lklma
			if (arr[i] == NULL)// protection case if memory allocation fails free and return NULL , 7imaya mn memory leaks
				return (ft_free(arr, i));
			s = s + len;// After extracting the word, we move the s pointer forward by len
						// (the length of the word) to position s at the next delimiter or word.
			i++;
		}
	}
	return (arr);
}
char *i = NULL;
#include <stdio.h>

int main()
{
char **result;
int i = 0;
char *str;
	ft_split();
result = ft_split("hello l lol", ' ');

while (result[i] )
{
	printf("%s\n", i[result]);
	i++;
}
	ft_free(result , i);
}