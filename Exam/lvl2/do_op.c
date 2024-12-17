/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:02:08 by malaamir          #+#    #+#             */
/*   Updated: 2024/12/17 11:53:04 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		if (av[2][0] == '+')
			printf("%d\n", atoi(av[1]) + atoi(av[3]));
		else if (av[2][0] == '-')
			printf("%d\n", atoi(av[1]) - atoi(av[3]));
		else if (av[2][0] == '*')
			printf("%d\n", atoi(av[1]) * atoi(av[3]));
		else if (av[2][0] == '/')
			printf("%d\n", atoi(av[1]) / atoi(av[3]));
		else if (av[2][0] == '%')
			printf("%d\n", atoi(av[1]) % atoi(av[3]));
	}
	else
		write(1, "\n", 1);
}