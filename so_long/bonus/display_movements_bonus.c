/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_movements_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:15:08 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/11 20:57:50 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_movements(t_map *map)
{
	char	*movement_str;

	movement_str = ft_itoa(map->movements);
	if (!movement_str)
		return ;
	mlx_clear_window(map->mlx, map->win);
	draw_map(map);
	mlx_string_put(map->mlx, map->win, 0, 0, 0x301934, "Moves: ");
	mlx_string_put(map->mlx, map->win, 80, 0, 0x301934, movement_str);
	free(movement_str);
}
