/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:18:16 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/15 11:37:34 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
void	f1(unsigned int i, char *str)
{
	*str = *str * 2;
}
int main()
{
	int c = 2333;

	char *str = (char *)&c;
	printf("3alama %s\n", str);
	ft_striteri(str, f1);
	 printf("%d\n", c);
 }
