/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:44:37 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/15 12:03:10 by malaamir         ###   ########.fr       */
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
	int *range = (int *)malloc(sizeof(int) * (end - start));
	
	while (i < len)
	{
		if (start < end)
		{
			range[i] = start;
			start++;
			i++;
		}
		else
		{
			range[i] = start;
			start--;
			i++;
	}
}
	return (range);
}
int main()
{
	int *range;
	int i = 0;
	range = ft_range(-1, 4);
	while (i < 5)
	{
		printf("%d\n", range[i]);
		i++;
	}
	return (0);
}