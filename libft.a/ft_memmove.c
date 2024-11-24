/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:23:10 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/14 21:29:14 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_dst;
	const char	*tmp_src;
	size_t		count;

	if (src == dst == NULL)
		return (NULL);
	tmp_dst = (char *) dst;
	tmp_src = (const char *) src;
	count = 0;
	if (tmp_dst > tmp_src)
		while (len-- > 0)
			tmp_dst[len] = tmp_src[len];
	else
	{
		while (count < len)
		{
			tmp_dst[count] = tmp_src[count];
			count++;
		}
	}
	return (dst);
}
