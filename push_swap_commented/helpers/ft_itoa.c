/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:15:48 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/17 14:16:58 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		return (ft_strdup("-2147483648"));
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
