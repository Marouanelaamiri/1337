/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:24 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/31 01:35:27 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_posi	ft_position(char **rows, int k)
{
	t_posi	pos;
	size_t	m;
	size_t	n;

	m = 0;
	n = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'P')
			{
				k = 1;
				break ;
			}
			n++;
		}
		if (k == 1)
			break ;
		m++;
	}
	return (pos.row = m, pos.column = n, pos);
}
