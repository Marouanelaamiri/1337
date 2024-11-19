/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:38:56 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/19 20:14:01 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ckeck_format(const char *str, va_list args, size_t *count)
{
	if (*str == 'c')
		ft_putchar_printf(va_arg(args, int), count);
	else if (*str == 's')
		ft_putstr_printf(va_arg(args, char *), count);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_printf(va_arg(args, int), count);
	else if (*str == 'u')
		ft_unsigned_printf(va_arg(args, unsigned int), count);
	else if (*str == '%')
		ft_putchar_printf('%', count);
	else if (*str == 'p')
		ft_putaddress_printf((size_t) va_arg(args, void *), count);
	else if (*str == 'x')
		ft_puthexa_printf(va_arg(args, unsigned int), count,
			"0123456789abcdef");
	else if (*str == 'X')
		ft_puthexa_printf(va_arg(args, unsigned int), count,
			"0123456789ABCDEF");
	else
		count += write(1, str, 1);
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
		return (-1);
	while (*str)
	{
		if (*str != '%')
		
			ft_putchar_printf(*str++, &count);
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
// int main()
// {
// 	ft_printf("Hello " "%s , %d , %c , %p , %x , %X\n", "world", 100, 'a', NULL, 3583, 3583);
// 	printf("Hello " "%s , %d , %c , %p , %x , %X", "world", 100, 'a', NULL, 3583, 3583);
// }