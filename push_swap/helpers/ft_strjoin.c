/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:59:30 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 18:41:57 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	size_t	maxlen;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	maxlen = (ft_strlen(s1) + ft_strlen(s2) + 1);
	newstr = (char *) malloc(maxlen);
	if (newstr == NULL)
		return (NULL);
	ft_memcpy(newstr, s1, ft_strlen(s1));
	ft_memcpy(&newstr[ft_strlen(s1)], s2, ft_strlen(s2));
	newstr[maxlen - 1] = '\0';
	return (newstr);
}
