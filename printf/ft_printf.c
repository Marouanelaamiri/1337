/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:38:56 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/21 18:23:58 by malaamir         ###   ########.fr       */
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
		return (-1 + count);
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
#include <libc.h>
static size_t	int_len(int nb)
{
	size_t	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count = 1;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	nb;

	nb = n;
	if (nb == -2147483648)
		return (strdup("-2147483648"));
	len = int_len(nb) + 1;
	str = malloc((len) * sizeof(char));
	if (!str)
		return (NULL);
	str[len - 1] = '\0';
	if (nb == 0)
		str[0] = '0';
	else if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		str[--len - 1] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

int main()
{
	// char **ptr = NULL;
	// // ft_printf("%s", *ptr);
	// printf("\n");
	// printf("%s", *ptr);
	// close(1);
	 fclose(stdout);
	//  fclose(stdout);
	int i;
	int j;
	i = ft_printf("rgerg");
	j = printf("rgerg");
	perror(ft_itoa(i));
	perror(ft_itoa(j));
	// ft_printf("%%%%l");
	// printf("\n");
	// printf("%%%%l");
}
