/* read
    ssize_t read(int fd, void *buf, size_t count);
    从fd读取
    buf:读取的数据存放在buf
    count: 可以比实际要读取的大，通常sizeof(buf)
读取成功，返回实际读到的字节数
读取失败，返回-1
返回值为0，到达文件结尾
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char **argv)
{
    int fd = open("1.txt", O_RDONLY);
    if (-1 == fd)
    {
        printf("open error\n");
        return 1;
    }
    while (1)
    {
        char buf[256] = {0};
        int ret = read(fd, buf, sizeof(buf));
        if (ret <= 0)
        {
            break;
        }
        printf("ret = %d,buf :\n[%s]\n", ret, buf);
    }
    close(fd);
    return 0;
}
