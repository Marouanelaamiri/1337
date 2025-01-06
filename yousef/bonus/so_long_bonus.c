/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:47:32 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/03 12:10:51 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	name_error(char *name)
{
	int	ls;

	ls = check_col_lenmap(name) - 1;
	if (name[ls - 3] != '.' || name[ls - 2] != 'b'
		|| name[ls - 1] != 'e' || name[ls] != 'r')
	{
		write(1, "Error!\n", 8);
		return (write(1, "map file extention not valid\n", 30), exit (1));
	}
}

void	check_map(char *map)
{
	if (!map)
	{
		write(1, "Error\n", 7);
		return (write(1, "map denied", 11), exit (1));
	}
}

void	check_and_rend(char **rows, char *map)
{
	map_check(rows);
	ft_rendering(map);
}

int	main(int argc, char **argv)
{
	char	*x_axis;
	char	*map;
	char	**rows;
	t_posi	player;

	if (argc != 2)
		return (write(1, "Error\nWrong number of arguments!", 33), exit(1), 0);
	else if (argc == 2)
	{
		x_axis = argv[1];
		name_error(x_axis);
		map = readingmap(x_axis);
		check_map(map);
		rows = ft_split(map, '\n');
		if (!rows)
			return (free(map), 0);
		map_parsing(rows, map);
		player = ft_position(rows, 0);
		rows = filling(rows, player.column, player.row);
		check_and_rend(rows, map);
	}
}
