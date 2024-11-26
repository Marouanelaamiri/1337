/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:28:24 by malaamir          #+#    #+#             */
/*   Updated: 2024/11/26 11:29:55 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_joinfree(char *buffer, char *new_buffer)
{
    char *holder;

    holder = ft_strjoin(buffer, new_buffer);
    free(buffer);
	buffer = NULL;
    return (holder);
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
	line = malloc(ft_strlen(buffer) - i + 1); //allocate space for the remaining data including 
	if (!line)								//the null terminator
		return (free (buffer), NULL);								           
	i++;			//skip the newline						
	while (buffer[i])
		line[j++] = buffer[i++]; // copy the remaining data from the buffer to the line 
	line[j] = '\0';
	free(buffer);
	// buffer = NULL;
	return (line); // return the remaining data (the updated data)
}
char	*ft_getline(char *buffer)// extract the line from the buffer
{
	char *line;
	int i;

	i = 0;
	if (!buffer[i])
		return (NULL); // if the buffer is empty return null
	while (buffer[i] && buffer[i] != '\n')
		i++; // we count len of the line till we fine a new line
	if (buffer[i] == '\n')
		line = malloc(i + 2); // we allocate space for the line including the null terminator and the newline
	else
		line = malloc(i + 1); // we allocate space for the line including just the null terminator

	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n') // copies characters from the buffer to the line till we reach the newline or the end of the buffer
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n') //  if a new line was found we add it to the line
		line[i++] = '\n';
	line[i] = '\0';
	return (line);	// return the extarcted line
}
char	*read_from_file(int fd, char *buffer)// read data into the static buffer
{
	char	*new_buffer;//holder
	int		bytes_read;

	new_buffer = malloc(BUFFER_SIZE + 1);// this tmp buffer we allocate space for the buffer of size BUFFER_SIZE + null terminator
	
	if (!new_buffer)
		return (NULL);
	while ((bytes_read = read(fd, new_buffer, BUFFER_SIZE)) > 0)// the read function reads up to BUFFER_SIZE bytes from the file and stors them in the buffer
																// it returns the number of bytes read if read is 0 it means we reached the end of the file , if read is -1 it means there was an error
	{ 
		new_buffer[bytes_read] = '\0';// add a null terminator
		buffer = ft_joinfree(buffer, new_buffer);// combines the previous buffer with the new buffer and free the old buffer
		if (!buffer)
			return (free(new_buffer), NULL);// if there was an error free the buffer and return null
		if (ft_strchr(new_buffer, '\n'))// stop reading when we find a newline
			break;
	}
		if (bytes_read == -1)
			return (free(new_buffer), NULL);

	free(new_buffer);// free the new(tmp) buffer
	return (buffer);// returns the updated buffer with data read from the file
}
char	*get_next_line(int fd)
{
	static char *buffer;//holder
	char *line;//store the next line
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(buffer), buffer = NULL,  NULL);
	buffer = read_from_file(fd, buffer);// filling up the container
	if (!buffer)// if there is no data left in the buffer return null
		return (NULL);
	line = ft_getline(buffer);// get the nextline(till newline)from buffer
	buffer = get_remaning (buffer);// we store leftover data (data after the newline) in the buffer
	if (!buffer)
		buffer = NULL;
	return (line);
}
// void f()
// {
// 	system("leaks a.out");
// }
// int main()
// {
// 	// atexit(f);
// 	int fd = open("test.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("------------>%s\n", line);
// 		free(line);
// 		line = get_next_line(fd);	
// 	}
// 	close(fd);
// }