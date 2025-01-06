#include<libc.h>
// #include "get_next_line_bonus.h"
#include "get_next_line.h"
// int main()
// {
//     int fd = open("file.txt", O_RDWR);
//     int fd1 = open("file1.txt", O_RDWR);
//     int fd2 = open("file2.txt", O_RDWR);
    
//     char *line1 = get_next_line(fd);
//     char *line2 = get_next_line(fd1);
//     char *line3 = get_next_line(fd2);

//     while (line1) {
//         if (line1) {
//             printf("#### File: file.txt ####\n%s", line1);
//             free(line1);
//             line1 = get_next_line(fd);
//         }
//         if (line2) {
//             printf("#### File: file1.txt ####\n%s", line2);
//             free(line2);
//             line2 = get_next_line(fd1);
//         }
//         if (line3) {
//             printf("#### File: file2.txt ####\n%s", line3);
//             free(line3);
//             line3 = get_next_line(fd2);
//         }
//     }
// }
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
    int i = 0;
	while(line && i < 3 )
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
        i++;
	}
}


// int main()
// {
// 	int fd = open("test.txt", O_RDWR | O_CREAT);
// 	write(fd ,"hello\n", 6);
// 	close(fd);
// 	fd = open("test.txt" , O_RDONLY);
// 	char *line = get_next_line(fd);
// 	while(line)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// }


// int main()
// {
// 	char *line = get_next_line(0);
// 	while(line)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = get_next_line(0);
// 	}
// }