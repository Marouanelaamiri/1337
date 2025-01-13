/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:39:51 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/12 13:33:01 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*read_line(int fd)
{
	char	*line;
	size_t	len;

	line = get_next_line(fd);
	if (line)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
	}
	return (line);
}

static void	read_map_data(int fd, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = read_line(fd);
		if (!line)
			break ;
		map->width = ft_strlen(line);
		map->data[i] = line;
		i++;
	}
	map->height = i;
	if (map->height == 0)
	{
		close(fd);
		display_error("Error: empty map\n");
	}
	if (map->height > 19 || ft_strlen(map->data[0]) > 34)
	{
		close(fd);
		display_error("Error: map too big\n");
	}
	map->data[i] = NULL;
}

t_map	*read_map(const char *file_path)
{
	int		fd;
	t_map	*map;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		display_error("Error: failed to open the map file\n");
	map = malloc(sizeof(t_map));
	if (!map)
	{
		close(fd);
		display_error("Error: failed to allocate memory for the map\n");
	}
	map->data = malloc(sizeof(char *) * 100);
	if (!map->data)
	{
		close(fd);
		display_error("Error: failed to allocate memory for the map data\n");
	}
	read_map_data(fd, map);
	close(fd);
	validate_map(map);
	return (map);
}

void	validate_map(t_map *map)
{
	if (!check_map_shape(map))
		display_error("Error: invalid map shape\n");
	if (!check_player_and_exit(map))
		display_error("Error: There is no exit or no player\n");
	if (!check_collectibles_and_enemy(map))
		display_error("Error: There is no collectible\n");
}
