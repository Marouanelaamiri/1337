/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:12:18 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/03 11:58:16 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_coin_frames(char *frames[])
{
	frames[0] = "textures/coin01.xpm";
	frames[1] = "textures/coin02.xpm";
	frames[2] = "textures/coin03.xpm";
	frames[3] = "textures/coin04.xpm";
	frames[4] = "textures/coin06.xpm";
	frames[5] = "textures/coin07.xpm";
	frames[6] = "textures/coin08.xpm";
	frames[7] = "textures/coin09.xpm";
	frames[8] = NULL;
}

void	set_enemy_frames(char *frames[])
{
	frames[0] = "textures/idle_01.xpm";
	frames[1] = "textures/idle_02.xpm";
	frames[2] = "textures/idle_03.xpm";
	frames[3] = "textures/idle_04.xpm";
	frames[4] = "textures/idle_05.xpm";
	frames[5] = "textures/idle_06.xpm";
	frames[6] = "textures/idle_07.xpm";
	frames[7] = "textures/idle_08.xpm";
	frames[8] = NULL;
}
