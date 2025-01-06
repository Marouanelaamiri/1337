/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:26 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/30 20:21:40 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*readingmap(char *row)
{
	int		buffer;
	char	*maps;
	char	*tmp;

	tmp = NULL;
	buffer = open(row, O_RDONLY, 0777);
	if (buffer < 0)
		return (write(1, "Error\n", 6), exit(1), NULL);
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
