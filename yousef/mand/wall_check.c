/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:36 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/31 01:25:53 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_row(char **rows)
{
	size_t	n;

	n = 0;
	while (rows[0][n])
	{
		if (rows[0][n] != '1')
		{
			write(1, "Error!\n", 7);
			write(1, "Map not fully surrounded with walls\n", 36);
			free_function(rows);
			exit(1);
		}
		n++;
	}
}

void	each_row(char **rows)
{
	size_t	m;
	size_t	col_len;

	m = 0;
	col_len = ft_strlen(rows[0]);
	while (rows[m])
	{
		if (rows[m][0] != '1' || rows[m][col_len - 1] != '1')
		{
			write(1, "Error!\n", 7);
			write(1, "Map not fully surrounded with walls\n", 36);
			free_function(rows);
			exit(1);
		}
		m++;
	}
}

void	last_row(char **rows)
{
	size_t	last_index;
	size_t	n;

	last_index = 0;
	while (rows[last_index])
		last_index++;
	last_index--;
	n = 0;
	while (rows[last_index][n])
	{
		if (rows[last_index][n] != '1')
		{
			write(1, "Error!\n", 7);
			write(1, "Map not fully surrounded with walls\n", 36);
			free_function(rows);
			exit(1);
		}
		n++;
	}
}
