/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:18:06 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/09 15:23:37 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)// function calculate the len of a str
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*#include<stdio.h>
int main()
{
	printf("%zu\n", ft_strlen("HELLO WORLD"));
}*/
