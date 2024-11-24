/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:08:15 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/20 10:13:46 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_printf(int nbr, size_t *count)
{
	long	nbr2;

	nbr2 = nbr;
	if (nbr2 < 0)
	{
		ft_putchar_printf('-', count);
		nbr2 *= -1;
	}
	if (nbr2 >= 10)
	{
		ft_putnbr_printf(nbr2 / 10, count);
		ft_putnbr_printf(nbr2 % 10, count);
	}
	else
		ft_putchar_printf(nbr2 + '0', count);
}
