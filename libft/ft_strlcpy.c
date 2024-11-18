/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:32:10 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/07 11:11:14 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)// we copy src into dst 
															// we have to ensure that dst does not overflow 
															// this function returns the len of the src that was copied
{
	size_t	i;

	i = 0;
	if (dstsize > 0) // we need dst to have some space 
	{
		if (dstsize > ft_strlen(src) + 1) // here we check if dst can hold src + null 
		{
			while (src[i])
			{
				dst[i] = src[i];// if dest is larg enough we copy
				i++;
			}
		}
		else // if dst is too small to hold the entire src, 
			//cpy only as many as it fits dstsize -1 for the null.
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
/*#include<stdio.h>
#include<string.h>
int main()
{
	char dst[1];
	char src[] = "hello";
	printf("dest befor copy : %s\n", dst);
//	printf("len of src : %zu\n", ft_strlcpy(dst, src, 5));
	printf("len of src with real strlcpy : %lu\n", strlcpy(dst, src, 5));
	printf("dest after copy : %s\n", dst);
}*/
