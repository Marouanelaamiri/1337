/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:45:05 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/13 10:08:32 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
// #include<libc.h>
// int main ()
// {

//  int fd = open("test1.txt",O_RDWR | O_CREAT , 0777);
//  int fd2 = open("test2.txt",O_RDWR | O_CREAT, 0777);
//  int fd3 = open("test3.txt",O_RDWR | O_CREAT, 0777);

// printf("File descriptor assigned to the file : %d\n", fd);
// printf("File descriptor assigned to the file : %d\n", fd2);
// printf("File descriptor assigned to the file : %d\n", fd3);
// ft_putchar_fd('1', fd);
// ft_putchar_fd('1', fd2);
// ft_putchar_fd('1', fd3);

// close(fd);
// close(fd2);
// close(fd3);

// // remove("test1.txt");
// // remove("test2.txt");
// // remove("test3.txt");

// return 0;
// }