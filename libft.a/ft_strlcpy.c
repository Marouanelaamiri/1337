/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:32:10 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/12 14:08:30 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		if (dstsize > ft_strlen(src) + 1)
		{
			while (src[i])
			{
				dst[i] = src[i];
				i++;
			}
		}
		else
		{
			while (i < dstsize - 1 && src[i])
			{
				dst[i] = src[i];
				i++;
			}
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
