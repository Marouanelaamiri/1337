/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:39:22 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 18:06:39 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_free(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}