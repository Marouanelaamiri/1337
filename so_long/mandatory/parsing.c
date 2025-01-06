/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:21 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/03 12:20:00 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_lines_check(char *maps, char **rows, int l)
{
	size_t	n;
	size_t	ls;

	n = 0;
	ls = check_len_rowsmap(rows);
	ls = (ls * (l + 1));
	while (maps[n])
	{
		if ((maps[n] == '\n' && maps[n + 1] == '\n')
			|| maps[0] == '\n' || maps[ls + 1] == '\n')
		{
			write(1, "Error\ndon't include empty rows", 31);
			return (free_function(rows), free(maps), exit(1));
		}
		if (maps[n] != 'P' && maps[n] != 'E'
			&& maps[n] != 'C' && maps[n] != '1'
			&& maps[n] != '0' && maps[n] != '\n')
		{
			write(1, "Error\nunknown elements encountered!", 36);
			return (free_function(rows), free(maps), exit(1));
		}
		n++;
	}
}

void	borders_check(char **rows)
{
	first_row(rows);
	each_row(rows);
	last_row(rows);
}

void	elements_check(char **rows, int p, int e, int c)
{
	size_t	n;
	size_t	m;

	n = 0;
	m = 0;
	while (rows[n])
	{
		m = 0;
		while (rows[n][m])
		{
			if (rows[n][m] == 'P')
				p++;
			else if (rows[n][m] == 'E')
				e++;
			else if (rows[n][m] == 'C')
				c++;
			m++;
		}
		n++;
	}
	if (p != 1 || e != 1 || c < 1)
	{
		write(1, "Error\nneed : 1 move, 1 coin and an exit", 40);
		return (free_function(rows), exit(1));
	}
}

void	map_parsing(char **rows, char *maps)
{
	checking_the_line(rows);
	map_lines_check(maps, rows, check_col_lenmap(rows[0]));
	borders_check(rows);
	elements_check(rows, 0, 0, 0);
}
