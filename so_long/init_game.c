/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:44:15 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/09 21:58:56 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_player_pos(t_map *map)
{
    int y;
    int x;

    y = 0;
    map->collectibles = 0;

    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->data[y][x] == 'P') // Player position
            {
                map->player_x = x;
                map->player_y = y;
            }
            else if (map->data[y][x] == 'C') // Collectibles count
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
	int win_width;
	int win_height;
    t_map *map_ptr;

    map_ptr = read_map(av[1]);
    if (ac != 2)
    {
        display_error("Error: you need to provide a map\n");
    }
    if (!check_map_extension(av[1]))
    {
        display_error("Error: Invalid map file extension. Map must end with .ber\n");
    }
    if (!map_ptr || !map_ptr->data)
    {
        display_error("Error: failed to read the map\n");
    }
    *map = *map_ptr;
    map->mlx = mlx_init();
    win_width = map->width * TILE_SIZE;
    win_height = map->height * TILE_SIZE;
    map->win = mlx_new_window(map->mlx, win_width, win_height, "So_long");
    init_player_pos(map);
}
