#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int fd = open("1.txt", O_RDONLY);
    if (-1 == fd)
    {
        printf("open error\n");
        return 1;
    }
    off_t off = lseek(fd, 0, SEEK_END);
    printf("size id %ld\n", off);

    lseek(fd, 0, SEEK_SET);
    char c = 0;
    read(fd, &c, 1);
    printf("c = %c\n", c);

    close(fd);
    return 0;
}
