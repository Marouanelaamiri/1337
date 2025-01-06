/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readingmap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:26 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/02 22:43:55 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*readingmap(char *row)
{
	int		buffer;
	char	*maps;
	char	*tmp;

	tmp = NULL;
	buffer = open(row, O_RDONLY, 0777);
	if (buffer < 0)
		return (write(1, "Error\n", 7), exit(1), NULL);
	maps = NULL;
	row = get_next_line(buffer);
	while ((row))
	{
		maps = ft_strjoin(maps, row);
		free(row);
		row = NULL;
		row = get_next_line(buffer);
	}
	return (close(buffer), maps);
}

void	borders_check(char **rows)
{
	first_row(rows);
	each_row(rows);
	last_row(rows);
}
