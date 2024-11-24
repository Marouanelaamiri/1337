/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:19:53 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/12 14:08:22 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	ch = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == ch)
		return ((char *)&s[i]);
	else
		return (NULL);
}
