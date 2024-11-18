/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:15:48 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/12 14:15:30 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(int nb)// static fucntions can only be used within this file
{
	size_t	count;

	count = 0;
	if (nb == 0)
		return (1);// 0 has one digit
	if (nb < 0)
	{
		count = 1;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb /= 10;// we keep removing chars by /10 and counting them till we reach 0 chars
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	nb;// to handle the min int value 

	nb = n;// so we can work with n without modifying directly
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len = int_len(nb) + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	str[len - 1] = '\0';// set last pos in the str to '\0'.
	if (nb == 0)
		str[0] = '0';
	else if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		str[--len - 1] = (nb % 10) + '0';//1st Iteration
		nb = nb / 10;
	}
	return (str);							
}
		// Current nb: 1234
		// Current len: 5
		// Calculate the last digit: (nb % 10) gives 4 (last digit).
		// Convert to character: 4 + '0' results in '4'.
		// Place in str: --len - 1 calculates the index 3 (len goes from 5 to 4), so str[3] = '4'.
		// Update nb: nb = nb / 10, which results in 123.
		// Current str: ['_', '_', '_', '4', '\0']
		// 2nd Iteration
		// Current nb: 123
		// Current len: 4
		// Calculate the last digit: (nb % 10) gives 3.
		// Convert to character: 3 + '0' results in '3'.
		// Place in str: --len - 1 gives index 2 (len goes from 4 to 3), so str[2] = '3'.
		// Current str: ['_', '_', '3', '4', '\0']
		// Update nb: nb = nb / 10, which results in 12.

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// int main()
// {
// 	int s = 'a';
//   //printf("%s\n", ft_itoa(s));
//   printf("%s\n", itoa(s, 20, 10));
// //   printf("%s\n", ft_itoa(0));// 0
// //   printf("%s\n", ft_itoa(-1));// -1
// //   printf("%s\n", ft_itoa(1));// 1
// //   printf("%s\n", ft_itoa(23));// 23
// //   printf("%s\n", ft_itoa(42));// 42
// //   printf("%s\n", ft_itoa(4711));// 4711
// //   printf("%s\n", ft_itoa(1000));// 1000
// //   printf("%s\n", ft_itoa(INT_MAX));// 2147483647
// //   printf("%s\n", ft_itoa(1 + INT_MIN));// -2147483647
// //   printf("%s\n", ft_itoa(INT_MIN)); // -2147483648
// }