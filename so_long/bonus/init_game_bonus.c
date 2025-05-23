/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:44:15 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/12 15:11:54 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_player_pos(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	map->collectibles = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->data[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
			}
			else if (map->data[y][x] == 'C')
			{
				map->collectibles++;
			}
			x++;
		}
		y++;
	}
}

void	init_game(int ac, char **av, t_map *map)
{
	int		win_width;
	int		win_height;
	t_map	*tmp_map;

	tmp_map = read_map(av[1]);
	if (ac != 2)
		display_error("Error: you need to provide a map\n");
	if (!check_map_extension(av[1]))
		display_error("Error: Invalid map file . Map must end with .ber\n");
	if (!tmp_map || !tmp_map->data)
		display_error("Error: failed to read the map\n");
	*map = *tmp_map;
	free(tmp_map);
	map->mlx = mlx_init();
	if (!map->mlx)
		display_error("Error: failed to initialize mlx\n");
	win_width = map->width * TILE_SIZE;
	win_height = map->height * TILE_SIZE;
	map->win = mlx_new_window(map->mlx, win_width, win_height, "So_long");
	if (!map->win)
		display_error("Error: failed to create window\n");
	init_player_pos(map);
}

void	check_unknown_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->data[i][j] != '1' && map->data[i][j] != '0' &&
				map->data[i][j] != 'P' && map->data[i][j] != 'E' &&
				map->data[i][j] != 'C' && map->data[i][j] != 'X')
			{
				display_error("Error: invalid map character\n");
				return ;
			}
			j++;
		}
		i++;
	}
}
