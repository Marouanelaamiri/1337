/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:02:30 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/13 10:13:17 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	int i ;

	i = 0;
	if (n == -2147483648)
	{
		ft_putchar_fd ('-', fd);
		ft_putchar_fd ('2', fd);
		ft_putnbr_fd (147483648, fd);
	}
	else if (n < 0)
	{
		i = write(fd, "-", 1);
		printf("|%d|\n", i);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putnbr_fd (n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}
int main()
{
	int fd = -1;
	ft_putnbr_fd(-110, fd);
	// write(1,"\n", 1);
	// ft_putnbr_fd(0, 1);
	// write(1,"\n", 1);
	// ft_putnbr_fd(-1, 1);
	// 	write(1,"\n", 1);
	// ft_putnbr_fd(10000, 1);
	// 	write(1,"\n", 1);
	// ft_putnbr_fd(-100000, 1);
	// 	write(1,"\n", 1);
	// ft_putnbr_fd(-2147483648, 1);
	// 	write(1,"\n", 1);
	// ft_putnbr_fd(2147483647, 1);
}