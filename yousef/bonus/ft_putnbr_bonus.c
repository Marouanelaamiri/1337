/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:02:56 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/31 19:15:39 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		n *= -1;
		count = count + write(1, "-", 1);
	}
	if (n > 9)
	{
		count = count + ft_putnbr(n / 10);
		count = count + ft_putnbr(n % 10);
	}
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		count = count + write(1, &n, 1);
	}
	return (count);
}
