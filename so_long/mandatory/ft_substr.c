/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:44:49 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/05 10:17:43 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
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
