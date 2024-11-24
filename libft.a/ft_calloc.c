/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:52:40 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/14 21:22:57 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if ((int)count < 0 && (int)size < 0)
		return (NULL);
	tmp = malloc(count * size);
	if (tmp == NULL)
	{
		return (NULL);
	}
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
int main()
{
	//ft_calloc(1000000 ,20000000000);
	char *p = ft_calloc(922337203685477580,922337203685477580);
}
