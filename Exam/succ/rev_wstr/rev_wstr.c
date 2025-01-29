/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:51:52 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/29 12:03:33 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int start;
	int end;
	int i = 0;

	if (ac == 2)
	{
		while (av[1][i])
			i++;
		while (i >= 0)
		{
			while (av[1][i] == '\0' || av[1][i] == ' ')
				i--;
			end = i;
			while (av[1][i] && av[1][i] != ' ')
				i--;
			start = i + 1;
			int flag;
			flag = start;
			while (start <= end)
			{
				write (1, &av[1][start++], 1);
			}
			if (flag != 0)
			{
				write(1, " ", 1);
			}
		}
	}
	write (1, "\n", 1);
}
