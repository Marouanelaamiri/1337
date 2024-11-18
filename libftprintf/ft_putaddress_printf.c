/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:20:20 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/18 16:41:49 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddress_printf(unsigned long n, size_t *count)
{
	char digits;
	char *base = "0123456789abcdef";
	if (n == 0)
	{
		write(1, "0x0", 3);
		(*count) += 3;
		return ;
	}
	
	if (n >= 16)
	{
		while(*count < 2)
		{
			write(1, "0x", 2);
			(*count) += 2;
			break;
		}
			
		ft_putaddress_printf(n / 16, count);
	}
	digits = base[(n % 16)];
	write(1, &digits, 1);
	(*count)++;
}
