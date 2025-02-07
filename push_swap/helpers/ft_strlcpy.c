/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:09:47 by malaamir          #+#    #+#             */
/*   Updated: 2025/02/07 12:10:09 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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