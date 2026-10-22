#include <stdio.h>
int main(int argc, char **argv)
{
    FILE *fp = fopen(argv[1], "r");
    if (NULL == fp)
    {
        printf("src open fail\n");
        return 1;
    }

    fseek(fp, 12, SEEK_SET);
    char buf[256] = {0};
    fgets(buf, sizeof(buf), fp);
    printf("buf : %s", buf);

    rewind(fp);  //回到文件最开始 = fseek(fp,0,SEEK_SET);
    fgets(buf, sizeof(buf), fp);
    printf("buf : %s", buf);

    fclose(fp);
    return 0;
}
