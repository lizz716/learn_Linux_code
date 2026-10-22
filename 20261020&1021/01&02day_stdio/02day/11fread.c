#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[64];
    int age;
    char address[100];
    char phone[20];
} PER;

int main(int argc, char **argv)
{
    PER per;

    FILE *fp = fopen("1.bin", "r");
    if (NULL == fp)
    {
        printf("open error\n");
        return 1;
    }
    fread(&per, sizeof(per), 1, fp);
    printf("name :%s\tage :%d\naddr :%s\tphone :%s\n", per.name, per.age, per.address, per.phone);
    fclose(fp);
    return 0;
}
