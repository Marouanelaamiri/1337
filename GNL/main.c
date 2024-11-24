#include<libc.h>
#include "get_next_line.h"
// void f()
// {
// 	system("leaks a.out");
// }
int main()
{
	// atexit(f);
	int fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s\n", line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}