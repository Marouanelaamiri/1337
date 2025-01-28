/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:10:47 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/28 11:35:23 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int inte(char *str, char c)
{
	int i = 0;
	while (str[i])
		if (str[i++] == c)
			return 1;
	return 0;
}

int main(int ac, char **av)
{
	int i;
	int j;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			j = 0;
			while (j < i)
			{
				if(av[1][i] == av[1][j])
				break;
			j++;
			}
			if (i == j && inte(av[2], av[1][i]))
				write (1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}

