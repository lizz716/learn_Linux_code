/*  open
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
    flags: O_RDONLY / O_WRONLY / O_RDWR
           O_CREATE 没有文件就创建 / O_TRUNC 清空
               ______________________________________________
              |     fopen   |    open                       |
              |     r       │ O_RDONLY                      │
              ├─────────────┼───────────────────────────────┤
              │     w       │ O_WRONLY | O_CREAT | O_TRUNC  │
              ├─────────────┼───────────────────────────────┤
              │     a       │ O_WRONLY | O_CREAT | O_APPEND │
              ├─────────────┼───────────────────────────────┤
              │     r+      │ O_RDWR                        │
              ├─────────────┼───────────────────────────────┤
              │     w+      │ O_RDWR | O_CREAT | O_TRUNC    │
              ├─────────────┼───────────────────────────────┤
              │     a+      │ O_RDWR | O_CREAT | O_APPEND   |
              ______________________________________________

    mode：权限，一般有创建文件选项就加   rm- rm- rm- 0666
打开成功，返回文件标识符（整形数）
打开失败，返回 -1 

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd = open("1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (-1 == fd)
    {
        printf("open error\n");
        return 1;
    }

    return 0;
}
