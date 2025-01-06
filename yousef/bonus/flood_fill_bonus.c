/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:02:27 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/03 12:16:28 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**filling(char **rows, int x, int y)
{
	if (!rows[y] || rows[y][x] == 'D' || rows[y][x] == '1')
		return (rows);
	rows[y][x] = 'D';
	rows = filling(rows, x + 1, y);
	rows = filling(rows, x - 1, y);
	rows = filling(rows, x, y + 1);
	rows = filling(rows, x, y - 1);
	return (rows);
}

void	check_map_len(char **rows)
{
	if (check_len_rowsmap(rows) > 17)
	{
		write(1, "Error\n", 7);
		return (write(1, "Too Many Lines!", 16), free_function(rows), exit(1));
	}
	if (check_col_lenmap(*rows) > 34)
	{
		write(1, "Error\n", 7);
		return (write(1, "Too Many Columns!", 18),
			free_function(rows), exit(1));
	}
}

void	map_check(char **rows)
{
	size_t	m;
	size_t	n;

	m = 0;
	n = 0;
	check_map_len(rows);
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'E' || rows[m][n] == 'C')
			{
				write(2, "Error\ncan't reach a door or a coin", 35);
				free_function(rows);
				exit(1);
			}
			n++;
		}
		m++;
	}
}
