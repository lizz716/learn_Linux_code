#include <stdio.h>
int main(int argc, char **argv)
{
    FILE *fp = fopen(argv[1], "r");
    if (NULL == fp)
    {
        printf("src open fail\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);

    long size = ftell(fp);
    //返回文件流的当前位置，单位是距离文件开头的字节数，与fseek配合可以获取文件大小（字节数）

    printf("size : %ld\n", size);

    fclose(fp);
    return 0;
}
