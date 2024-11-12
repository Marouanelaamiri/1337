/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:23:59 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/06 14:00:57 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)// this function returns a pointer to the memory that have been modified (b)

{
	unsigned char	*tmp;

	tmp = (unsigned char *)b;// b is a pointer to a block of memory 
	while (len > 0)// this loop will run till all len byts have been set 
	{
		*tmp = (unsigned char)c;// int c is the value we want to set to the memory 
		tmp++;
		len--;
	}
	return (b);
}
//ft_memset is like filling a row of boxes with the same item. You fill one box
//at a time, and after you’ve filled the number of boxes specified by len, you stop
//It’s useful for setting blocks of memory to a known value, like initializing an
//array with zeros or setting all values to a specific character.



// /*#include<stdio.h>
// int main()
// {
// 	int i;
// 	ft_memset((unsigned char *)&i ,199, sizeof(int));
// 	ft_memset((unsigned char *)&i + 1, 250, sizeof(int) );
// 	ft_memset((unsigned char *)&i + 2 ,255 , sizeof(int));
// 	ft_memset((unsigned char *)&i + 3, 255 , sizeof(int));
// 	printf("%d\n", i);
// }
// 	//int i = 0; // to --> -1337
// 	//ft_memset((char *)&i ,57, 1);
// 	//ft_memset((char *)&i + 1, 250, 1);
// 	//ft_memset((char *)&i + 2, 255, 1);
// 	//ft_memset((char *)&i + 3, 255, 1);
// 	//printf("%d\n", i);
// 	/*int i = 0;
// 	 ft_memset(&i, 5 , 2);
// 	 ft_memset(&i , 57 , 1);
// 	 printf("%d\n", i);*/
// 	/* char str[20];
// 	ft_memset(str, '1' ,1 );
// 	ft_memset(str + 1, '3', 1);
// 	ft_memset(str+ 2, '3' ,1);
// 	ft_memset(str + 3, '7',1);
// 	ft_memset(str + 4,'\0', 1);
// 	 printf("%s\n", str);*/