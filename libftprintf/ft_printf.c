/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:38:56 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/18 18:13:56 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ckeck_format(const char *str, va_list args, size_t *count)
{
	char	*baselow;
	char	*baseup;

	baselow = "0123456789abcdef";
	baseup = "0123456789ABCDEF";
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
		ft_puthexa_printf(va_arg(args, unsigned int), count, baselow);
	else if (*str == 'X')
		ft_puthexa_printf(va_arg(args, unsigned int), count, baseup);
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
		{
			ft_putchar_printf(*str, &count);
			str++;
		}
		else
		{
			str += 1;
			ckeck_format(str, args, &count);
			str++;
		}
	}
	va_end(args);
	return (count);
}
// int main()
// {
// 	ft_printf("%d\n", -42);
// 	printf("%d\n", -42);
// 	ft_printf("%s\n",NULL);
// 	printf( "%s\n",NULL);
// 	ft_printf("%c\n", '\0');
// 	printf("%c\n", '\0');
// 	ft_printf("%u\n", -10000);
// 	printf("%u\n", -10000);
// 	ft_printf("%%\n");
// 	printf("%%\n");
// 	ft_printf("%p\n", NULL);
// 	printf("%p\n", NULL);
// 	ft_printf("%x\n", 42222);
// 	printf("%x\n", 42222);
// 	ft_printf("%X\n", 4222233);
// 	printf("%X\n", 4222233);
// 	ft_printf("hello world , %u, %i, %d, %p\n" , 42 , -32, 1929292, NULL);
// 	printf("hello world, %u, %d, %i, %p" , 42 , -32, 1929292, NULL);
// }