/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:59:47 by malaamir          #+#    #+#             */
/*   Updated: 2024/12/19 15:55:24 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//firstword

/*int main(int ac, char **av)
{
	int i = 0;
	if (ac == 2)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			av[1][i] += 1 ;
		while (av[1][i] != ' ' && av[1][i] != '\t' &&  av[1][i] != '\0')
			write (1, &av[1][i],1);
			i++;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int main()
{
	int i = 1;
	while(i <= 100)
	{
		if (i % 3 == 0 || i % 5 == 0)
			write(1, "fizzbuzz",8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write (1, "buzz", 4);
		else
			ft_putnbr(i);
		i++;
		write(1, "\n", 1);
	}
}

void	ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}
int main()
{
	ft_putstr("hello world");
}
*/

char	*ft_strcpy(char *s1, char *s2)
{
	int i = 0;

	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
#include<stdio.h>

int main()
{
	char s1[] = "hello";
	char s2[] = "world";

	printf("%s\n", ft_strcpy(s1, s2));
}
