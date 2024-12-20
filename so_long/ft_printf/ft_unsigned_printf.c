/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:59:19 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/19 20:12:17 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_printf(unsigned int n, size_t *count)
{
	if (n >= 10)
		ft_unsigned_printf (n / 10, count);
	ft_putchar_printf ((n % 10) + '0', count);
}
