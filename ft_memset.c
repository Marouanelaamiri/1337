/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marouane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:36:55 by marouane          #+#    #+#             */
/*   Updated: 2024/10/26 13:26:37 by marouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *tmp;

	tmp = (unsigned char *)b;
	while (len > 0)
	{
		*tmp = (unsigned char)c;
		tmp++;
		len--;
	}
	return b;
}
#include <stdio.h>


int main() {
    char str[50] = "Hello, World!";
    printf("Before memset: %s\n", str);

    ft_memset(str, '*', 13); 

    printf("After memset: %s\n", str);

    return 0;
}
