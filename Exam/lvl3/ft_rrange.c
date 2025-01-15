/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:03:45 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/15 12:10:09 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>

int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
int *ft_range(int start, int end)
{
	int i = 0;
	int len = ft_abs(end - start) + 1;
	int *range = (int *)malloc(sizeof(int) * (len));
	
	while (i < len)
	{
		if (end < start)
		{
			range[i] = end;
			end++;
			i++;
		}
		else
		{
			range[i] = end;
			end--;
			i++;
	}
}
	return (range);
}
int main()
{
	int *range;
	int i = 0;
	range = ft_range(0, 3);
	while (i < 4)
	{
		printf("%d\n", range[i]);
		i++;
	}
	return (0);
}