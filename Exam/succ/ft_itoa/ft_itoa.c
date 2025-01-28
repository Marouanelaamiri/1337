/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:35:10 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/28 14:26:29 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char    *ft_itoa(int nbr)
{
	int	len = 0;
	int	n = nbr;
	int tmp;
	char *str;

	if (n == -2147483648)
		return ("-2147483648\0");
	
	tmp = n;
	if (n <= 0)
	{
		n = -n;
		len++;
	}

	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] ='\0';

	if (nbr == 0)
	{
		str[0] = '0';
		return (str); 
	}

	while (n > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	if (nbr < 0)
		str[0] = '-';

	return (str);
}
