/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:57:51 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/04 18:53:49 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}
/*#include <stdio.h>
#include <sys/fcntl.h>
int main()
{
	int fd = open("tets", O_RDWR, 0);
	ft_putendl_fd("hello", fd);
	printf("%d\n", fd);
	int lfd = open("test", O_RDWR, 0);
	printf("%d\n", lfd);
	ft_putendl_fd("hello", lfd);
	return 0;
}*/