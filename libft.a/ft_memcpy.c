/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:22:10 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/14 21:33:53 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
int main()
{
	char src[] = "abcd";
	// char dst[] = "abcd";
	printf("%s\n",ft_memcpy(src, src, 5));

}
