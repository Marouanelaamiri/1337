/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:58:41 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/08 12:36:55 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_map map) // this function will draw the map
{
	int x;
	int y;
    int x_pos;
    int y_pos;

    y = 0;
    while (y < map.height)
    {
        x = 0; 
        while (x < map.width)
        {
             x_pos = x * TILE_SIZE;
             y_pos = y * TILE_SIZE;
            mlx_put_image_to_window(map.mlx, map.win, map.img_floor, x_pos, y_pos); // always render the floor first
            if (map.data[y][x] == '1')
                mlx_put_image_to_window(map.mlx, map.win, map.img_wall, x_pos, y_pos);
            else if (map.data[y][x] == 'P')
                mlx_put_image_to_window(map.mlx, map.win, map.img_player, x_pos, y_pos);
            else if (map.data[y][x] == 'E')
                mlx_put_image_to_window(map.mlx, map.win, map.img_exit, x_pos, y_pos);
            else if (map.data[y][x] == 'C')
                mlx_put_image_to_window(map.mlx, map.win, map.img_collectible, x_pos, y_pos);
            x++;
        }
        y++;
    }
}
