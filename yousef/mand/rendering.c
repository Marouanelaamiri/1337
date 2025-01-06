/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:29 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/30 21:06:59 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_function(t_info *pic)
{
	free(pic);
	exit(0);
}

void	ft_rendering(char *map)
{
	t_info	*pic;
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (write(1, "Error!\n fix render!", 20), free(map), exit(1));
	pic = malloc(sizeof(t_info));
	if (!pic)
		return (free(map), exit (1));
	pic->rows = ft_split(map, '\n');
	pic->move = 1;
	free(map);
	fetch_pic(pic, mlx_ptr);
	rendersize_background(pic->rows, pic);
	rendersize_wall(pic->rows, pic);
	rendersize_door(pic->rows, pic);
	rendersize_character(pic->rows, pic);
	rendersize_coin(pic->rows, pic);
	mlx_hook(pic->mlx_window, 2, 0, ft_keycodes, pic);
	mlx_hook(pic->mlx_window, 17, 0, clean_function, pic);
	mlx_loop(pic->mlx_ptr);
}
