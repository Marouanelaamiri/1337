#include<libc.h>
#include "get_next_line_bonus.h"
void f()
{
	system("leaks a.out");
}
int main()
{
	atexit(f);
	int fd = open("file.txt", O_RDONLY);
	int fd1 = open("file1.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_RDONLY);
	// int i = 0;
	char *line;
	printf("####file1###\n");
	while ((line = get_next_line(fd)) != NULL)	
	{
		printf("%s", line);
		free(line);
		// line = get_next_line(fd);
		// i++;
	}
	printf("####file2####\n");
	while ((line = get_next_line(fd1)) != NULL)	
	{
		printf("%s", line);
		free(line);
		// line = get_next_line(fd);
		// i++;
	}
	printf("####file3####\n");
	while ((line = get_next_line(fd2)) != NULL)	
	{
		printf("%s", line);
		free(line);
		// line = get_next_line(fd);
		// i++;
	}
	// free(line);
	close(fd);
}
