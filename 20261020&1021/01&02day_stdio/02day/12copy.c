#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int size = atoi(argv[3]);
    int *buf = malloc(size);
    if (NULL == buf)
    {
        printf("malloc fail\n");
        return 1;
    }

    FILE *fp1 = fopen(argv[1], "r");
    if (NULL == fp1)
    {
        printf("src open fail\n");
        return 1;
    }

    FILE *fp2 = fopen(argv[2], "w");
    if (NULL == fp2)
    {
        printf("dst open fail\n");
        return 1;
    }

    fread(buf, size, 1, fp1);
    fwrite(buf, size, 1, fp2);

    free(buf);
    fclose(fp1);
    fclose(fp2);

    return 0;
}