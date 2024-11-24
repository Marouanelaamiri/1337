/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:28:24 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/24 19:52:51 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
    char *temp;

    temp = ft_strjoin(buffer, buf);
    free(buffer);
    return (temp);
}
char	*get_remaning(char *buffer)// extract the remaining data from the buffer
{
	int i;
	int j;
	char *line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++; // find the end of the line
	if(!buffer[i])
	{
		free(buffer); // if there is no data remaining free the buffer and return null
		return (NULL);
	}
	line = malloc(ft_strlen(buffer) - i + 1); 
	if (!line)
		return (NULL);								             // allocate space for the remaining data including 
	i++;									//the null terminator - i + 1 is for putting the null terminator at the end
	while (buffer[i])
		line[j++] = buffer[i++]; // copy the remaining data from the buffer to the line 
	line[j] = '\0';
	free(buffer);
	return (line); // return the remaining data (the updated data)
}
char	*getline(char *buffer)// extract the line from the buffer
{
	char *line;
	int i;

	i = 0;
	if (!buffer[i])
		return (NULL); // if the buffer is empty return null
	while (buffer[i] && buffer[i] != '\n')
		i++; // we count len of the line till we fine a new line
	line = malloc(i + 2); // we allocate space for the line including the null terminator and the newline
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n') // copies characters from the buffer to the line till we reach the newline or the end of the buffer
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n') //  if a new line was found we add it to the line
	{
		line[i++] = '\n';
	}
	line[i] = '\0';
	return (line);	// return the extarcted line
}
char	*read_from_file(int fd, char *str)// read data into the static buffer
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	
	if (!buffer)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)// we allocate space for the buffer of size BUFFER_SIZE and reads data into it
	{
		buffer[bytes_read] = '\0';
		str = ft_free(str, buffer);
		if (!str)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n'))//
			break;
	}
	free(buffer);
	return (str);// returns the updated buffer with data read from the file
}
char	*get_next_line(int fd)
{
	static char *buffer;
	char *line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer = read_from_file(fd, buffer);
	if (!buffer)
		return (NULL);
	
	line = getline(buffer);
	buffer = get_remaning (buffer);
	return (line);
}
// void f()
// {
// 	system("leaks a.out");
// }
// int main()
// {
// 	atexit(f);
// 	int fd = open("test.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = get_next_line(fd);	
// 	}
// 	close(fd);
// }