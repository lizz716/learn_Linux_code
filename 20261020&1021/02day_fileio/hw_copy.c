#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("uasge:./copy old_file new_file\n");
        return 1;
    }

    int srcfd = open(argv[1], O_RDONLY);
    if (-1 == srcfd)
    {
        // printf("old_file open fail\n");
        fprintf(stderr, "old_file open error\n");
        return 1;
    }
    int dstfd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (-1 == dstfd)
    {
        printf("new_file open fail\n");
        return 1;
    }
    /*
        char *buf = malloc(size);
        if (NULL == buf)
        {
            printf("malloc buf fail\n");
            return 1;
        }
        int ret = read(srcfd, buf, size);

        write(dstfd, buf, size);
    */
    while (1)
    {
        char buf[4096] = {0};  //使用1k～4k范围
        int ret = read(srcfd, buf, sizeof(buf));
        if (0 == ret)
        {
            break;
        }
        write(dstfd, buf, ret);  //对于操作照片等二进制文件，sizeof，strlen 都有问题，使用read的返回值，读多少写多少
    }

    close(srcfd);
    close(dstfd);
    return 0;
}
