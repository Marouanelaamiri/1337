/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:09:42 by malaamir          #+#    #+#             */
/*   Updated: 2025/04/10 17:50:47 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		*len += write(1, str++, 1);
	}
}

void put_digit(long long int nb, int base, int *len)
{
	if (nb < 0)
	{
		nb += -1;
		*len += write(1, "-", 1);
	}
	if (nb >= base)
		put_digit((nb / base), base, len);
	*len += write (1, &("0123456789abcdef"[nb % base]), 1);
}

int ft_printf(const char *format, ...)
{
	int len = 0;
	
	va_list ptr;
	va_start(ptr, format);
	
	while(*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				put_digit((long long int)va_arg(ptr, int), 10, &len);
			else if (*format == 'x')
				put_digit((long long int)va_arg(ptr , unsigned int), 16 , &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (len);
}

int main()
{
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("%%%l");
}
