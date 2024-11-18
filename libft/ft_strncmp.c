/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:31:17 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/17 15:08:11 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)//this funcion compare 2 strings char by char for max of n
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;
	if (!s1 && !s2 && n <= 0)
		return (0);

	str1 = (unsigned char *)s1;// we cat so we have more range 255, and we dont face problems with ascii values
	str2 = (unsigned char *)s2;
	i = 0;
	while ((s1[i] || s2[i]) && i < n) // we keep goin till we reach the end of one of the strs and we dont exeed n
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
#include<stdio.h>
#include<string.h>
int main(void)
{
    printf("%d\n", strncmp((const char ) 120, 0, 0));
    // printf("%d\n", ft_strncmp((const char) 120, 0, 0));
    return 0;
}