/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_enemy_pack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:23:33 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/03 12:28:15 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	rendersize_enemy(char **rows, t_infob *pic)
{
	size_t	m;
	size_t	n;

	m = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'Y')
				mlx_put_image_to_window((pic)->mlx_ptr, (pic)->mlx_window,
					(pic)->pic_ef[pic->current_ef], n * 75, m * 75);
			n++;
		}
		m++;
	}
	pic->current_ef = (pic->current_ef + 1) % pic->num_ef;
}

void	get_texture_enemy(t_infob *pic, void *mlx_ptr)
{
	int		i;
	char	*frames[9];

	set_enemy_frames(frames);
	pic->mlx_ptr = mlx_ptr;
	pic->current_ef = 0;
	i = 0;
	while (frames[i])
	{
		pic->pic_ef[i] = mlx_xpm_file_to_image(pic->mlx_ptr,
				frames[i], &pic->pic_width, &pic->pic_height);
		if (!(pic->pic_ef[i]))
		{
			write(1, "Error!\n can't get the enemy's image!", 37);
			free(pic);
			exit(1);
		}
		i++;
	}
	pic->num_ef = i;
}

void	handle_win_message(t_infob *pic)
{
	write(1, "Congratulations 🎉🥳🎊, YOU WON!\n", 40);
	free(pic);
	exit(0);
}

void	handle_loss_message(t_infob *pic)
{
	write(1, "YOU LOST! You touched an enemy! 😔\n", 38);
	free(pic);
	exit(0);
}
