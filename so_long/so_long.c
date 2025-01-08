/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:24:30 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/08 18:29:56 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    display_error(const char *msg)
{
    write(2, msg, ft_strlen(msg));
    exit(1);
}
void    load_images(t_map *map) // this function will load the images
{
    map->img_floor = mlx_xpm_file_to_image(map->mlx, "textures/floor.xpm", &map->img_width, &map->img_height);
    map->img_wall = mlx_xpm_file_to_image(map->mlx, "textures/wall.xpm", &map->img_width, &map->img_height);
    map->img_exit = mlx_xpm_file_to_image(map->mlx, "textures/door.xpm", &map->img_width, &map->img_height);
    map->img_collectible = mlx_xpm_file_to_image(map->mlx, "textures/diam.xpm", &map->img_width, &map->img_height);
    map->img_player = mlx_xpm_file_to_image(map->mlx, "textures/player1.xpm", &map->img_width, &map->img_height);

    if (!map->img_floor || !map->img_wall || !map->img_exit || 
        !map->img_collectible || !map->img_player)
    {
        display_error("Error: failed to load images\n");
    }
    
}
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
int main()
{
    t_map map;
    t_map *map_ptr = read_map("maps/map.ber");

    if (!map_ptr || !map_ptr->data) {
        display_error("Error: This map does not exist\n");
        return (1);
    }

    map = *map_ptr;
    map.mlx = mlx_init();

    int win_width = map.width * TILE_SIZE;
    int win_height = map.height * TILE_SIZE;

    map.win = mlx_new_window(map.mlx, win_width, win_height, "So_long");
    init_player_pos(&map);// Initialize the player position
    load_images(&map);// Load the images
    draw_map(map);// Draw the map

    mlx_key_hook(map.win, key_hook, &map);// Set the key hook
	mlx_hook(map.win, 17, 0, close_window, &map);// Set the close window hook
    mlx_loop(map.mlx);// Start the game loop

    free_map(map_ptr);// Free the map
    destroy_images(&map);// Destroy the images
    return 0;
}
