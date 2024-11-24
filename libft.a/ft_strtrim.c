/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:53:53 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/12 14:00:00 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	maxlen;
	size_t			start;
	size_t			end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	while (end > 0 && ft_strchr(set, s1[end]) && end >= 0)
		end--;
	maxlen = (end - start + 1);
	if (maxlen <= 0)
		return (ft_strdup(""));
	return (ft_substr(s1, start, maxlen));
}
