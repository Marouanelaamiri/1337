/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:31:32 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/23 19:31:33 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int ft_atoi(char *s)
{
    int res = 0, i = 0;
    while (s[i] && s[i] >= 48 && s[i] <= 57)
    {
        res *= 10;
        res += s[i] - 48;
        i++;
    }
    return (res);
}

void ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

void ft_putstr(char *s)
{
    int i = 0;
    while (s[i])
        write(1, &s[i++], 1);
}

int main(int ac, char **av)
{

    if (ac != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
	int i = 1;
	int n = ft_atoi(av[1]);
    while (i < 10)
    {
        ft_putnbr(i);
        ft_putstr(" x ");
        ft_putnbr(n);
        ft_putstr(" = ");
        ft_putnbr(i * n);
        write(1, "\n", 1);
        i++;
    }
}