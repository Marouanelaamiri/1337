/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:23:10 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/06 13:45:48 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)//same as memcpy but it protect against overlaping 
{
	char		*tmp_dst;
	const char	*tmp_src;
	size_t		count;

	if (src == NULL && dst == NULL)			//we cant work with invalid memory adresses , so we return NULL
		return (NULL); 
	tmp_dst = (char *) dst;				 // we are dealing with memory so its best to work with char (1byte)
	tmp_src = (const char *) src;
	count = 0;
	if (tmp_dst > tmp_src)				// overlap handling 
		while (len-- > 0) 				// if dst is higher in memory than src then we cpy from the end ,
			tmp_dst[len] = tmp_src[len];// we keep decremnting so we move to the next 
											
	else
	{
		while (count < len) 			// here is the standrad case we copy from the start byte by byte
		{
			tmp_dst[count] = tmp_src[count];
			count++;
		}
	}
	return (dst);
}

/*#include<stdio.h>
#include<string.h>
int main()
{
	char src[20] = "hello";
	char dst[20] = "world";
	
	printf("befor : %s\n", dst);
	printf("after : %s\n", ft_memmove(dst, src, 6));
	printf("after : %s\n", memmove(dst, src, 6));
}*/
