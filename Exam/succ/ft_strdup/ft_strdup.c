/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:16:14 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/23 18:24:12 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strdup(char *src)
{
	char *tmp;
	int len = 0;
	int i = 0;

	while(src[len])
		len++;
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
	{
		return NULL;
	}
	while (src[i])
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

