/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:42:37 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/23 15:58:06 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		if (av[2][0] == '+')
			printf("%d\n",atoi(av[1]) + atoi(av[3]));
		else if (av[2][0] == '-')
			printf("%d\n", atoi(av[1]) - atoi(av[3]));
		else if (av[2][0] == '*')
			printf("%d\n", atoi(av[1]) * atoi(av[3]));
		else if (av[2][0] == '%')
			printf("%d\n", atoi(av[1]) % atoi(av[3]));
		else if (av[2][0] == '/')
			printf("%d\n", atoi(av[1]) / atoi(av[3]));
	}
	else
		write(1, "\n", 1);
		return 0;
}

