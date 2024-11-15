/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:32:30 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/11 11:04:41 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)// void *s means that the pointer s can point to any type of data
{
	
	char	*tmp;

	tmp = (char *)s;// we used char cuz its 1 byte it work best for memory manipulation
	while (n > 0)
	{
		*tmp = '\0';
		tmp++;
		n--;// de decrease n meaning now there is less byte to erase.
	}
}
#include<stdio.h>
#include<string.h>
int main()
{
	char str[] = "";
	size_t n = 5;
	printf("befor : %s\n", str);

	ft_bzero(str, n);
	bzero(str, n);

	printf("after : %s\n", str);
}
