/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:24:30 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/13 12:59:46 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		display_error("Error: failed to allocate memory\n");
		return (1);
	}
	map->movements = 0;
	init_game(ac, av, map);
	check_unknown_characters(map);
	if (!check_path(map))
	{
		display_error("Error: invalid map path\n");
		return (1);
	}
	load_images(map);
	draw_map(map);
	mlx_key_hook(map->win, key_hook, map);
	mlx_hook(map->win, 17, 0, close_window, map);
	mlx_loop(map->mlx);
	free_map(map);
	destroy_images(map);
	return (0);
}
