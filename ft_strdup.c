/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:21:55 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/10 18:05:07 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)// this function creat a duplicat of a string and allocate a 
								// new memory for it 
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = malloc(ft_strlen(s1) + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str[1024];
// 	memset(str, 'a' , 1023);
// 	printf("ft_strdup : %s\n", ft_strdup(str));
// 	printf("strdup : %s\n", strdup(str));
	
// }