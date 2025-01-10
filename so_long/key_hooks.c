/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:01:29 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/10 11:48:34 by malaamir         ###   ########.fr       */
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
		if (map->data[new_y][new_x] == 'E')
	{
		if (map->collectibles == 0)
		{
			write(1, "GOOD JOB GAMER!\n", 16);
			exit(0);
		}
			return(1);
	}
	return (1);
}
int move_player(t_map *map, int new_x, int new_y)
{
    if (map->data[new_y][new_x] == '1')
        return (0);
	if (!check_exit(map, new_x, new_y))
		return (0);
    check_collectible(map, new_x, new_y);
    if (map->data[map->player_y][map->player_x] == 'E')
		put_image(map, map->player_x, map->player_y, map->img_exit);
	else
		put_image(map, map->player_x, map->player_y, map->img_floor);

    map->player_x = new_x;
    map->player_y = new_y;

    if (map->data[new_y][new_x] == 'E')
    {
        put_image(map, new_x, new_y, map->img_exit);
    }
    put_image(map, new_x, new_y, map->img_player);

    return (1);
}
int key_hook(int keycode, t_map *map)
{
    int new_x;
    int new_y;

    new_x = map->player_x;
    new_y = map->player_y;

    if (keycode == 0)
        new_x--;
    else if (keycode == 1)
        new_y++;
    else if (keycode == 2)
        new_x++;
    else if (keycode == 13)
        new_y--;
    if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
    {
        if (map->data[new_y][new_x] != '1' && map->data[new_y][new_x] != '\0')
        {
            if (move_player(map, new_x, new_y))
            {
                map->movements++;
                ft_printf("Movements: %d\n", map->movements);
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
