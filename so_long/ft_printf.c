/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:38:56 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/08 18:57:47 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	ckeck_format(const char *str, va_list args, size_t *count)
{
	if (*str == 'c')
		ft_putchar_printf(va_arg(args, int), count);
	else if (*str == 's')
		ft_putstr_printf(va_arg(args, char *), count);
	else if (*str == '%')
		ft_putchar_printf('%', count);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_printf(va_arg(args, int), count);
}

int	ft_printf(const char *format, ...)
{
	size_t		count;
	const char	*str;
	va_list		args;

	count = 0;
	str = format;
	va_start(args, format);
	if (write(1, str, 0) == -1)
		return (-1 + count);
	while (*str)
	{
		if (*str != '%')
			ft_putchar_printf(*str++, &count);// %%%l
		else
		{
			str++;
			ckeck_format(str, args, &count);
			if (*str == '\0')
				break ;
			str++;
		}
	}
	va_end(args);
	return (count);
}

