/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:08:15 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/19 20:11:20 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_printf(int nbr, size_t *count)
{
	if (nbr == -2147483648)
	{
		ft_putstr_printf("-2147483648", count);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar_printf('-', count);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr_printf(nbr / 10, count);
		ft_putnbr_printf(nbr % 10, count);
	}
	else
		ft_putchar_printf(nbr + '0', count);
}
