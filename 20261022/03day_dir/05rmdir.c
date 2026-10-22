//删空目录
// remove 删除文件
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{

    int ret = rmdir("new");
    if (-1 == ret)
    {
        fprintf(stderr, "rmdir error\n");
        return 1;
    }
    return 0;
}