/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:01:29 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/09 12:27:19 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_collectible(t_map *map, int new_x, int new_y)
{
	if (map->data[new_y][new_x] == 'C')
	{
		map->collectibles--;
		map->data[new_y][new_x] = '0';
	}
}
int check_exit(t_map *map, int new_x, int new_y)
{
		if (map->data[new_y][new_x] == 'E') // If the tile is an exit
	{
		if (map->collectibles == 0) // All collectibles collected
		{
			write(1, "GOOD JOB GAMER!\n", 16);
			exit(0);
		}
			return(0);// Can't move onto the door if collectibles remaining
	}
	return (1);
}
int	move_player(t_map *map, int new_x, int new_y)
{
	if (map->data[new_y][new_x] == '1') // Wall
		return (0);
	if (!check_exit(map, new_x, new_y)) // Check exit conditions
		return (0);
	check_collectible(map, new_x, new_y); // Handle collectibles
	map->data[map->player_y][map->player_x] = '0'; // Clear old position
	map->player_x = new_x;
	map->player_y = new_y;
	map->data[map->player_y][map->player_x] = 'P'; // Place player
	draw_map(*map); // Draw the map
	return (1);
}
int key_hook(int keycode, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = map->player_x;
	new_y = map->player_y;
	if (keycode == 0)
		new_x--; // Move left
	else if (keycode == 1)
		new_y++; // Move down
	else if (keycode == 2)
		new_x++; // Move right
	else if (keycode == 13)
		new_y--; // Move up
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
    {
		   if (map->data[new_y][new_x] != '1' &&
            !(map->data[new_y][new_x] == 'E' && map->collectibles > 0) && //block the player from exiting if there are still collectibles
            map->data[new_y][new_x] != '\0')
        {
			if (move_player(map, new_x, new_y)) // Move player to new position
			{
				map->movements++; // Increment movement count
        		ft_printf("Movements: %d\n", map->movements); // Print the movement count
			}
		}
    }
	if (keycode == 53)
	{
		if (map->collectibles > 0)
			write(1, "NOOB YOU CANT BEAT A CHILD GAME!\n", 34);
		exit(0);
	}
	return (0);
}
