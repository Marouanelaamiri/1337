/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:02:29 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/31 16:15:37 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_door_open(t_info *pic)
{
	char	**rows;
	int		b;

	rows = pic->rows;
	b = check_coins(rows);
	if (b == 0)
		ft_door(rows, pic);
}

int	ft_keycodes(int button, void *p)
{
	t_info	*pic;

	pic = p;
	if (button == 13)
		up(p);
	else if (button == 0)
		left(p);
	else if (button == 1)
		down(p);
	else if (button == 2)
		right(p);
	else if (button == 53)
	{
		ft_printf("YOU QUIT THE GAME, IS IT HARD FOR YOU ? ;( \n");
		exit(0);
	}
	is_door_open(pic);
	return (0);
}

void	ren_again(t_info *pic, t_posi coor, char **rows)
{
	mlx_put_image_to_window(pic->mlx_ptr,
		pic->mlx_window, pic->pic_background, coor.column * 75, coor.row * 75);
	if (rows[(coor.row)][coor.column] == 'E')
		mlx_put_image_to_window(pic->mlx_ptr,
			pic->mlx_window, pic->pic_closeddoor,
			coor.column * 75, coor.row * 75);
}
