/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:08:27 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/05 10:17:35 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
