/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:37:56 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/28 11:59:13 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void str_capitalizer(char *str)
{
	int i = 0 ;

	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	write(1, &str[i], 1);
	while(str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
 		if ((str[i] >= 'a' && str[i] <= 'z' ) && (str[i - 1] == ' ')) 
			str[i] -= 32;
		write(1, &str[i], 1);
	}
}

int main(int ac, char **av)
{
	int i;

	if (ac < 2)
		write (1, "\n", 1);
	else
	{
		i = 1;
		while (i < ac)
		{
			str_capitalizer(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return 0;
}
