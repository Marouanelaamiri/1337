/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:40:03 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/06 09:44:29 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_whitespaces(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ') // handle all kind of spaces
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long long	result; // we assigned long long for the case below 

	i = 0;
	sign = 1;
	result = 0;
	while (ft_whitespaces(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0'); // we multiply by 10 to shit the digits to the left
		if (result > LONG_MAX && sign == 1)//this case if to handl long ints 
			return (-1);
		if (result > LONG_MAX && sign == -1)
			return (0);
		i++;
	}
	return (result * sign);
}
/*#include <stdio.h>

int main ()
{
    printf("%d\n", ft_atoi("-9223372036854775809"));
    printf("%d\n", atoi("-9223372036854775809"));
    printf("%d\n", ft_atoi("2147483648"));
    printf("%d\n", atoi("2147483648"));
    printf("%d\n", ft_atoi("-2147483649"));
    printf("%d\n", atoi("-2147483649"));
}*/