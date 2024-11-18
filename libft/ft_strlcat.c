/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:30:27 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/07 10:56:15 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)// this function concatenates 2 strs
															// and it ensures that the total lent of dst does not 
															// exeed the limit of dstsize, it returns the len od the str it tried to create
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	if (dst_len >= dstsize)
		return (dstsize + src_len); // if the dst already have a larg size or equal to our limit dstsize
									// this means there is no room for src so we just return the combined size , 
									//without actualy combining it 
	if (dstsize > 0)//meaning if there is room 
	{
		while (src[i] && dst_len + i < dstsize - 1)// keep going till u reach null and obv leave space for '\0'.
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';// ensure we finalize the dst with '\0'.
	}
	return (dst_len + src_len);
}
/*#include <stdio.h>
#include <string.h>
int main()
{
	char dst[20] = "";
	char src[20] = "hello";
	printf("dst befor concat : %s\n", dst);
	printf("len of both str ft_strlcat : %zu\n", ft_strlcat(dst, src, 20));
//	printf("len of both str real strlcat : %zu\n", strlcat(dst, src, 20));
	printf("new dst : %s\n", dst);
}*/
