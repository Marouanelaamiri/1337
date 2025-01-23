/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:02:47 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/23 16:10:35 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int nb1 = atoi(av[1]);
		int nb2 = atoi(av[2]);
		if (nb1 > 0 && nb2 > 0)
		{
			while(nb1 != nb2)
			{
				if ( nb1 > nb2 )
					nb1 = nb1 - nb2;
				else
					nb2 = nb2 - nb1;
			}
			printf("%d\n", nb1);
		}
	}
	else
		printf("\n");
}


