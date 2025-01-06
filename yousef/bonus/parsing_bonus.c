/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:21 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/02 23:37:21 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			&& maps[n] != '0' && maps[n] != 'Y'
			&& maps[n] != '\n')
		{
			write(1, "Error\nunknown elements encountered!", 36);
			return (free_function(rows), free(maps), exit(1));
		}
		n++;
	}
}

void	count_elements(char **rows, int *elements)
{
	size_t	n;
	size_t	m;

	n = 0;
	while (rows[n])
	{
		m = 0;
		while (rows[n][m])
		{
			if (rows[n][m] == 'P')
				elements[0]++;
			else if (rows[n][m] == 'E')
				elements[1]++;
			else if (rows[n][m] == 'C')
				elements[2]++;
			else if (rows[n][m] == 'Y')
				elements[3]++;
			m++;
		}
		n++;
	}
}

void	validate_elements(int *elem)
{
	if (elem[0] != 1 || elem[1] != 1 || elem[2] < 1 || elem[3] < 1)
	{
		write(1, "Error\n", 6);
		write(1, "need: 1 player, 1 exit, at least 1 coin, and 1 enemy\n", 55);
		exit(1);
	}
}

void	elements_check(char **rows)
{
	int	elements[4];

	elements[0] = 0;
	elements[1] = 0;
	elements[2] = 0;
	elements[3] = 0;
	count_elements(rows, elements);
	validate_elements(elements);
}

void	map_parsing(char **rows, char *maps)
{
	checking_the_line(rows);
	map_lines_check(maps, rows, check_col_lenmap(rows[0]));
	borders_check(rows);
	elements_check(rows);
}
