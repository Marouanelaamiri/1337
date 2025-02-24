/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:27:44 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/20 17:20:47 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_printf(unsigned long int n, size_t *count, const char *c)
{
	char	digits;

	if (n >= 16)
	{
		ft_puthexa_printf(n / 16, count, c);
	}
	digits = c[(n % 16)];
	write(1, &digits, 1);
	(*count)++;
}
