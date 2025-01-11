/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:08:27 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/11 19:07:49 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putstr_printf(char *str, size_t *count)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar_printf(*str, count);
		str++;
	}
}
