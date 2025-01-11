/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:37:07 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/11 19:12:52 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_collectibles(t_map *map)
{
	int	collectible;
	int	i;
	int	j;

	collectible = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->data[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if (collectible > 0)
		return (1);
	return (0);
}

int	check_player_and_exit(t_map *map)
{
	int	player;
	int	exit;
	int	i;
	int	j;

	player = 0;
	exit = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->data[i][j] == 'P')
				player++;
			if (map->data[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1)
		return (0);
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map->width)
	{
		if (map->data[i][j] != '1' || map->data[map->height - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < map->height)
	{
		if (map->data[i][0] != '1' || map->data[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_shape(t_map *map)
{
	int	i;

	i = 0;
	if (!check_walls(map))
		return (0);
	while (i < map->height)
	{
		if ((int)ft_strlen(map->data[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}

int	check_map_extension(const char *file_path)
{
	size_t	len;

	len = ft_strlen(file_path);
	if (len < 4)
		return (0);
	if (ft_strcmp(file_path + len - 4, ".ber") == 0)
		return (1);
	return (0);
}
