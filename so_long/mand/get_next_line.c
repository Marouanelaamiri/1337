/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:28:24 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/10 18:06:31 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_joinfree(char *buffer, char *new_buffer)
{
	char	*holder;

	holder = ft_strjoin(buffer, new_buffer);
	free(buffer);
	buffer = NULL;
	return (holder);
}

char	*get_remaning(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = malloc(ft_strlen(buffer) - i + 1);
	if (!line)
		return (free (buffer), NULL);
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*ft_getline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_from_file(int fd, char *buffer)
{
	char	*new_buffer;
	int		bytes_read;

	new_buffer = malloc(BUFFER_SIZE + 1);
	if (!new_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, new_buffer, BUFFER_SIZE);
		new_buffer[bytes_read] = '\0';
		buffer = ft_joinfree(buffer, new_buffer);
		if (!buffer)
			return (free(new_buffer), NULL);
		if (ft_strchr(new_buffer, '\n'))
			break ;
	}
	if (bytes_read == -1)
		return (free(new_buffer), NULL);
	free(new_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(buffer), buffer = NULL, NULL);
	buffer = read_from_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = get_remaning (buffer);
	if (!buffer)
		buffer = NULL;
	return (line);
}
