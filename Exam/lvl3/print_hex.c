/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:12:13 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/15 12:14:34 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	
	while (*str)
	{
		i = i * 10 + *str - '0';
		str++;
	}
	return (i);
}
void print_hex(int n)
{
	char *base = "0123456789abcdef";
	if (n >= 16)
		print_hex(n / 16);
	write(1, &base[n % 16], 1);
}
int main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}