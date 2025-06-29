/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nex_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:09:42 by malaamir          #+#    #+#             */
/*   Updated: 2025/04/17 16:13:44 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

# define BUFFER_SIZE 42
#ifndef BUFFER_SIZE
#endif

char *get_next_line(int fd);

#endif



#include <unistd.h>
#include <stdlib.h>

# define BUFFER_SIZE 42
#ifndef BUFFER_SIZE
#endif

char *ft_strdup(char *src)
{
	char *tmp;
	int len = 0;
	int i = 0;

	while (src[len])
		len++;
	tmp = malloc(len + 1);
	while (i < len)
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	char	line[70000];
	static int buffer_readed;
	static int buffer_pos;
	int i;
	
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	
	while (1)
	{
		if (buffer_pos >= buffer_readed)
		{
			buffer_readed = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_readed <= 0)
				break ;
		}
		line[i++] = buffer[buffer_pos++];
		if (line [i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return NULL;
	return (ft_strdup(line));
}
