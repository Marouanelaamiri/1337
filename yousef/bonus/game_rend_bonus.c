/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rend_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:05 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/02 22:58:10 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	rendersize_wall(char **rows, t_infob *pic)
{
	size_t	m;
	size_t	n;

	m = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == '1')
				mlx_put_image_to_window((pic)->mlx_ptr,
					(pic)->mlx_window, (pic)->pic_wall, n * 75, m * 75);
			n++;
		}
		m++;
	}
}

void	rendersize_character(char **rows, t_infob *pic)
{
	size_t	m;
	size_t	n;

	m = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'P')
			{
				mlx_put_image_to_window((pic)->mlx_ptr,
					(pic)->mlx_window, (pic)->pic_character, n * 75, m * 75);
				break ;
			}
			n++;
		}
		m++;
	}
}

void	rendersize_coin(char **rows, t_infob *pic)
{
	size_t	m;
	size_t	n;

	m = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'C')
				mlx_put_image_to_window((pic)->mlx_ptr, (pic)->mlx_window,
					(pic)->pic_cf[pic->current_cf], n * 75, m * 75);
			n++;
		}
		m++;
	}
	pic->current_cf = (pic->current_cf + 1) % pic->num_cf;
}

void	rendersize_door(char **rows, t_infob *pic)
{
	size_t	m;
	size_t	n;

	m = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'E')
			{
				mlx_put_image_to_window((pic)->mlx_ptr,
					(pic)->mlx_window, pic->pic_closeddoor, n * 75, m * 75);
				break ;
			}
			n++;
		}
		m++;
	}
}

void	rendersize_background(char **rows, t_infob *pic)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (rows[i])
	{
		j = 0;
		while (rows[i][j])
		{
			mlx_put_image_to_window((pic)->mlx_ptr,
				(pic)->mlx_window, (pic)->pic_background, j * 75, i * 75);
			j++;
		}
		i++;
	}
}
