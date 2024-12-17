/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:57:30 by malaamir          #+#    #+#             */
/*   Updated: 2024/12/17 18:06:08 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;
	size_t j;

	while(s[i])
	{
		j = 0;
		while(accept[j])
		{
			if(s[i] == accept[j])
				break;
			j++;
		}
		if(!accept[j])
			return (i);
		i++;
	}
	return (i);
}
int main()
{
	const char *s = "     Hello World";
	const char *accept = " ";
	printf("%zu\n", ft_strspn(s, accept));
	return 0;
}