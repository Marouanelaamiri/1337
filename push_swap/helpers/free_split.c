/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:48:01 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/30 21:33:12 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_split(char **split_result)
{
	int	i;

	i = 0;
	if (!split_result)
		return ;
	while (split_result[i])
	{
		free (split_result[i]);
		i++;
	}
	free (split_result);
}
