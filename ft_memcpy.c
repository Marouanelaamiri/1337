/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:22:10 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/07 11:05:57 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)//this function will return a pointer to dst
{
	unsigned char		*tmp_dst;
	unsigned const char	*tmp_src;
	size_t				i;

	if (src == NULL && dst == NULL)// if both dont point to anything we return the dest as the function wants
	{
		return (dst);
	}
	 if (src == dst)// we check if both src and dst are at the same memory location, meaning they are copying memory to itself 
	 				//makes no sense so we return dst again.
		return (dst);
	
	i = 0;
	tmp_dst = (unsigned char *)dst;// as usual we are working with memory so we cast to unsigned char
	tmp_src = (unsigned const char *)src;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];//cpy byt by byt to dst
		i++;//move to the next byte
			//decremnt cuz we'v copied one byte
	}
	return (dst);
}
#include<stdio.h>
#include<string.h>
int main()
{
	// char src [] = "hello";
	char *src = "hello";
	char *dst = "hello";
	printf("befor : %p\n", dst);
	printf("befor : %p\n", src);
	//printf("after : %p\n", ft_memcpy(dst, src, 1));
	printf("after : %p\n", memcpy(dst, src, 1));
}