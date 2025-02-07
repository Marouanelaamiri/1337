/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:33:09 by malaamir          #+#    #+#             */
/*   Updated: 2025/02/06 17:34:06 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_words(char *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	if (words_count <= 0)
		return (NULL);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	i = 0;
	result_array[i] = malloc(sizeof(char));
	if (!result_array[i])
		return (free_split(result_array), NULL);
	result_array[i++][0] = '\0';
	while (words_count-- > 0)
	{
		result_array[i] = get_next_word(s, c);
		if (!result_array[i++])
			return (free_split(result_array), NULL);
	}
	result_array[i] = NULL;
	return (result_array);
}
