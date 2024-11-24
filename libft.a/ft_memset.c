/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:23:59 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/13 15:32:47 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)b;
	while (len > 0)
	{
		*tmp = (unsigned char)c;
		tmp++;
		len--;
	}
	return (b);
}
#include<libc.h>
int main()
{
	int i = 1337 ;
	char *str;
	str = ft_itoa(-1337);
	int c = str[0];
	 ft_memset(str, c , 1);
	i = ft_atoi(str);
	printf("%d\n", i);
}
// 	int i;
// 	memset((unsigned char *)&i ,199, sizeof(int));
// 	memset((unsigned char *)&i + 1, 250, sizeof(int) );
// 	memset((unsigned char *)&i + 2 ,255 , sizeof(int));
// 	memset((unsigned char *)&i + 3, 255 , sizeof(int));
// 	printf("%d\n", i);
//