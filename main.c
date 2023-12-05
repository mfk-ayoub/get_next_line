#include "get_next_line_bonus.h"

int main()
{
    int fd = open("ayoub1.txt", O_RDONLY);
    int fd1 =  open("ayoub2.txt", O_RDONLY);
    
    char *line = get_next_line(fd);
    printf("%s", line);
    char *line1 = get_next_line(fd1);
    printf("%s\n", line1);
    char *line2 = get_next_line(fd);
    printf("%s\n", line2);
    char *line3 = get_next_line(fd1);
    printf("%s\n", line3);

    free(line);
    free(line1);
    free(line2);
    free(line3);
}