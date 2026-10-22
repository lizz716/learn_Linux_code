/*  write
 ssize_t write(int fd, const void *buf, size_t count);
    fd：写入文件的文件标识符（open后的返回值）
    buf：要写入的数据（void * 类型，可以传入任何类型的数据）
    count:写入字节数 buf中的有效字节数
成功，返回写入的字节数（正常情况下，返回值 = count）
失败，返回-1

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char **argv)
{
    int fd = open("1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (-1 == fd)
    {
        printf("open error\n");
        return 1;
    }
    char buf[256] = "how are you";

    write(fd, buf, strlen(buf));  //操作字符串时 用strlen
    return 0;
}
