/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:24:30 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/09 22:08:41 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void f(void)
{
	system("leaks so_long");
}

int main(int ac, char **av)
{
    t_map map;

	atexit(f);
    // Pass the map file path directly to init_game
    init_game(ac, av ,&map);

	if (!check_path(&map))
	{
		display_error("Error: invalid map path\n");
		return (1);
	}

    load_images(&map);   
    draw_map(map);              // Draw the map

    mlx_key_hook(map.win, key_hook, &map); // Set the key hook
    mlx_hook(map.win, 17, 0, close_window, &map); // Set the close window hook
    mlx_loop(map.mlx);          // Start the game loop

    free_map(&map);
    destroy_images(&map);
    return 0;
}
