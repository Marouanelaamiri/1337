/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:58:41 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/12 11:50:48 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_images(t_map *map)
{
	map->img_floor = mlx_xpm_file_to_image(map->mlx, "textures/floor.xpm",
			&map->img_width, &map->img_height);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, "textures/wall.xpm",
			&map->img_width, &map->img_height);
	map->img_exit = mlx_xpm_file_to_image(map->mlx, "textures/door1.xpm",
			&map->img_width, &map->img_height);
	map->img_collectible = mlx_xpm_file_to_image(map->mlx, "textures/diam.xpm",
			&map->img_width, &map->img_height);
	map->img_player = mlx_xpm_file_to_image(map->mlx, "textures/player.xpm",
			&map->img_width, &map->img_height);
	map->img_exit_open = mlx_xpm_file_to_image(map->mlx, "textures/door2.xpm",
			&map->img_width, &map->img_height);
	map->img_enemy = mlx_xpm_file_to_image(map->mlx, "textures/enemy.xpm",
			&map->img_width, &map->img_height);
	if (!map->img_floor || !map->img_wall || !map->img_exit
		|| !map->img_collectible || !map->img_player
		|| !map->img_exit_open || !map->img_enemy)
	{
		display_error("Error: failed to load images\n");
	}
}

void	put_image(t_map *map, int x, int y, void *img)
{
	int	x_pos;
	int	y_pos;

	x_pos = x * TILE_SIZE;
	y_pos = y * TILE_SIZE;
	mlx_put_image_to_window(map->mlx, map->win, img, x_pos, y_pos);
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			put_image(map, x, y, map->img_floor);
			if (map->data[y][x] == '1')
				put_image(map, x, y, map->img_wall);
			else if (map->data[y][x] == 'E' && map->collectibles == 0)
				put_image(map, x, y, map->img_exit_open);
			else if (map->data[y][x] == 'E')
				put_image(map, x, y, map->img_exit);
			else if (map->data[y][x] == 'C')
				put_image(map, x, y, map->img_collectible);
			else if (map->data[y][x] == 'X')
				put_image(map, x, y, map->img_enemy);
			x++;
		}
		y++;
	}
	put_image(map, map->player_x, map->player_y, map->img_player);
}
