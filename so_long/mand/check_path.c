/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:38:32 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/10 18:01:26 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(int x, int y, t_map *map, int **visited)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (visited[y][x] || map->data[y][x] == '1')
		return ;
	visited[y][x] = 1;
	flood_fill(x + 1, y, map, visited);
	flood_fill(x - 1, y, map, visited);
	flood_fill(x, y + 1, map, visited);
	flood_fill(x, y - 1, map, visited);
}

int	**init_visited(t_map *map)
{
	int	**visited;
	int	i;
	int	j;

	visited = malloc(map->height * sizeof(int *));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		visited[i] = malloc(map->width * sizeof(int));
		if (!visited[i])
		{
			free_visited(visited, map);
			return (NULL);
		}
		j = 0;
		while (j < map->width)
			visited[i][j++] = 0;
		i++;
	}
	flood_fill(map->player_x, map->player_y, map, visited);
	return (visited);
}

int	check_path(t_map *map)
{
	int	**visited;
	int	i;
	int	j;

	i = 0;
	visited = init_visited(map);
	if (!visited)
		return (0);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if ((map->data[i][j] == 'C' || map->data[i][j] == 'E')
				&& !visited[i][j])
			{
				free_visited(visited, map);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_visited(visited, map);
	return (1);
}
