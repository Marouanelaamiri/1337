/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_movements_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:15:08 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/12 13:37:44 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_movements(t_map *map)
{
	char	*movement_str;

	movement_str = ft_itoa(map->movements);
	if (!movement_str)
		return ;
	mlx_put_image_to_window(map->mlx, map->win, map->img_floor, 0, 0);
	mlx_put_image_to_window(map->mlx, map->win, map->img_floor, 80, 0);
	draw_map(map);
	mlx_string_put(map->mlx, map->win, 0, 0, 0xFFFF00, "Moves: ");
	mlx_string_put(map->mlx, map->win, 80, 0, 0xFFFF00, movement_str);
	free(movement_str);
}
