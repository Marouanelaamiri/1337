/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:12:21 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/12 12:47:36 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_error(const char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
	free(map);
}

void	free_visited(int **visited, t_map *map)
{
	int	i;

	if (!visited)
		return ;
	i = 0;
	while (i < map->height)
	{
		if (visited[i])
			free(visited[i]);
		i++;
	}
	free(visited);
}

void	destroy_images(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img_floor);
	mlx_destroy_image(map->mlx, map->img_wall);
	mlx_destroy_image(map->mlx, map->img_exit);
	mlx_destroy_image(map->mlx, map->img_collectible);
	mlx_destroy_image(map->mlx, map->img_player);
}

int	close_window(t_map *map)
{
	destroy_images(map);
	write(1, "Game has been closed!\n", 23);
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
	return (0);
}
