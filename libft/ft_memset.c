/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:23:59 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/15 18:34:25 by malaamir         ###   ########.fr       */
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



#include<stdio.h>
int main()
{
	int i = 12312; //	-340
	ft_memset(&i, 255, 4);
	ft_memset(&i, 254, 2);
	ft_memset(&i, 172 , 1);
	printf("%d\n", i);
}
