/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:37:07 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/09 21:39:59 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player_and_exit(t_map *map)
{
	int player;
	int exit;
	int i;
	int j;

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
	int i;
	int j;

	i = 0;
	j = 0;
	while(j < map->width)
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
int check_map_shape(t_map *map)
{
	int i;

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
int check_map_extension(const char *file_path)
{
	size_t len = ft_strlen(file_path);
	if (len < 4)
		return (0);
	 if (ft_strcmp(file_path + len - 4, ".ber") == 0)
        return 1;

    return 0;
}
t_map	*read_map(const char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    if (fd == -1)
        display_error("Error: failed to open the map file\n");
    t_map *map = malloc(sizeof(t_map));
    if (!map)
        display_error("Error: failed to allocate memory for the map\n");
    map->data = malloc(sizeof(char *) * 100);
    if (!map->data)
        display_error("Error: failed to allocate memory for the map data\n");
    char *line;
    int i;

	i = 0;
    while ((line = get_next_line(fd)))
    {
        size_t len = ft_strlen(line);
        if (line[len - 1] == '\n')
            line[len - 1] = '\0';  // remove the newline character
        if (i == 0)
			map->width = ft_strlen(line);
        	map->data[i] = line;
        i++;
    }
    map->height = i;
    map->data[i] = NULL;
    close(fd);
	if (!check_map_shape(map))
		display_error("Error: invalid map shape\n");
	if (!check_player_and_exit(map))
		display_error("Error: invalid player or exit\n");
    return map;
}
