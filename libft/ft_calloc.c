/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:52:40 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/10 14:35:45 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)//allocate and clean 
{
	unsigned char	*tmp;// we used again char cuz its best for memory manipulation
	size_t			i;

	if ((int)count < 0 || (int)size < 0)
		return (NULL);
	i = 0;
	tmp = malloc(count * size);
	if (tmp == NULL)
		return (NULL);
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
// #include<stdio.h>
// #include<string.h>
// int main()
// {
// 	printf("%s\n", ft_calloc (-4 , -1));
// 	printf("%s\n", calloc (-4 , -1));
// }