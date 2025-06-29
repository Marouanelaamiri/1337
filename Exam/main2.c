/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:17:14 by malaamir          #+#    #+#             */
/*   Updated: 2025/04/18 09:27:40 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif
char *ft_strdup(char *src)
{
	char *dst;
	int len = 0;
	int i = 0;

	while(src[len])
		len++;
	dst = malloc(len + 1);
	while ( i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return dst;
}
char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	char line[700000];
	static int buffer_readed;
	static int buffer_pos;
	int i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	while(1)
	{
		if (buffer_pos >= buffer_readed)
		{
			buffer_readed = read(fd , buffer,  BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_readed <= 0)
				break;
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
		return NULL;
	return(ft_strdup(line));
}

