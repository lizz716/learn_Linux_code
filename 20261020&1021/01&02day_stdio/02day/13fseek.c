#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *fp = fopen(argv[1], "r");
    if (NULL == fp)
    {
        printf("src open fail\n");
        return 1;
    }

    fseek(fp, 12, SEEK_SET);  //要操作的文件，偏移量，开始偏移位置（SEEK_SET从头开始|SEEK_END从最后开始|SEEK_CUR从当前位置开始）
    char buf[256] = {0};

    char *ret = fgets(buf, sizeof(buf), fp);
    printf("buf : %s", buf);

    fclose(fp);

    return 0;
}
