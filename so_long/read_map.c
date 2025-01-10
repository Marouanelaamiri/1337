/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:39:51 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/10 13:58:10 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*read_map(const char *file_path)
{
    int fd;
    char *line;
    int i;
	t_map *map;
	
	fd = open(file_path, O_RDONLY);
    if (fd == -1)
        display_error("Error: failed to open the map file\n");
    map = malloc(sizeof(t_map));
    if (!map)
        display_error("Error: failed to allocate memory for the map\n");
    map->data = malloc(sizeof(char *) * 100);
    if (!map->data)
        display_error("Error: failed to allocate memory for the map data\n");

	i = 0;
    while ((line = get_next_line(fd)))
    {
        size_t len = ft_strlen(line);
        if (line[len - 1] == '\n')
            line[len - 1] = '\0';
        if (i == 0)
			map->width = ft_strlen(line);
        	map->data[i++] = line;
    }
    map->height = i;
    map->data[i] = NULL;
    close(fd);
	validate_map(map);
    return map;
}
void validate_map(t_map *map)
{
    if (!check_map_shape(map))
        display_error("Error: invalid map shape\n");

    if (!check_player_and_exit(map))
        display_error("Error: There is no exit or no player\n");

	if (!check_collectibles(map))
        display_error("Error: There is no collectible\n");
}
