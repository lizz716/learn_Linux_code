#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
    // argv[1] file_name | argv[2] data |argv[3] spot
    if (argc != 4)
    {
        printf("uasge:./insert filename str spot_num\n");
        return 1;
    }

    FILE *srcfp = fopen(argv[1], "r+");
    if (NULL == srcfp)
    {
        printf("fopen error\n");
        return 1;
    }
    int set = atoi(argv[3]);

    fseek(srcfp, 0, SEEK_END);
    long size_all = ftell(srcfp);
    fseek(srcfp, set, SEEK_SET);
    long size_set = ftell(srcfp);
    long size_end = size_all - size_set;  //算剩下的长度,总长度-插入位置的长度

    char *per = malloc(size_end);
    if (NULL == per)
    {
        printf("per malloc error\n");
        return 1;
    }

    fseek(srcfp, set, SEEK_SET);
    fread(per, size_end, 1, srcfp);  //将剩余字符串写入per

    fseek(srcfp, set, SEEK_SET);
    fwrite(argv[2], strlen(argv[2]), 1, srcfp);  //先将要插入的数据写入
    fwrite(per, size_end, 1, srcfp);             //再将保存的后面的数据写入

    fclose(srcfp);
    free(per);

    return 0;
}
