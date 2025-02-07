/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:04:20 by malaamir          #+#    #+#             */
/*   Updated: 2025/02/07 12:07:32 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp_dst;
	unsigned const char	*tmp_src;
	size_t				i;

	if (src == NULL && dst == NULL)
	{
		return (dst);
	}
	i = 0;
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned const char *)src;
	while (n > 0)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
		n--;
	}
	return (dst);
}

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