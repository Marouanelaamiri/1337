/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:02:32 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/31 19:16:47 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	door_checker(char **rows)
{
	size_t	m;
	size_t	n;

	m = 0;
	n = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'E' || rows[m][n] == 'X')
				return (1);
			n++;
		}
		m++;
	}
	return (0);
}

int	check_coins(char **rows)
{
	size_t	m;
	size_t	n;
	int		coin;

	m = 0;
	n = 0;
	coin = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'C')
				coin++;
			n++;
		}
		m++;
	}
	return (coin);
}

void	handle_door(t_infob *pic, char **rows, size_t m, size_t n)
{
	mlx_put_image_to_window(pic->mlx_ptr,
		pic->mlx_window, pic->pic_background, n * 75, m * 75);
	if (rows[m][n + 1] == '0')
		mlx_put_image_to_window(pic->mlx_ptr,
			pic->mlx_window, pic->pic_background, (n + 1) * 75, m * 75);
	mlx_put_image_to_window(pic->mlx_ptr,
		pic->mlx_window, pic->pic_opendoor, n * 75, m * 75);
}

void	ft_door(char **rows, t_infob *pic)
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
				rows[m][n] = 'X';
				handle_door(pic, rows, m, n);
				break ;
			}
			n++;
		}
		m++;
	}
}
