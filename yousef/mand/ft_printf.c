/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:02:41 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/30 20:11:42 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	format_pf(char f, va_list arg)
{
	int	count;

	count = 0;
	if (f == '%')
		count = count + ft_putchar('%');
	else if (f == 'c')
		count = count + ft_putchar(va_arg(arg, int));
	else if (f == 's')
		count = count + ft_putstr(va_arg(arg, char *));
	else if (f == 'd' || f == 'i')
		count = count + ft_putnbr(va_arg(arg, int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	arg;

	count = 0;
	va_start(arg, str);
	while (*str != '\0')
	{
		if (write(1, "", 0) < 0)
			return (-1);
		if (*str == '%')
			count = count + format_pf(*(++str), arg);
		else
			count = count + write(1, str, 1);
		str++;
	}
	va_end(arg);
	return (count);
}
