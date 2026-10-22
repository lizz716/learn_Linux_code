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

    printf("Input name :");
    fgets(per.name, sizeof(per.name), stdin);  // stdin是标准输入——键盘
    per.name[strlen(per.name) - 1] = '\0';     //将读取输入的最后一个 ‘\n’ 换成 ‘\0’

    printf("Input age :");
    scanf("%d", &per.age);
    getchar();

    printf("Input address :");
    fgets(per.address, sizeof(per.address), stdin);
    per.address[strlen(per.address) - 1] = '\0';

    printf("Input phone :");
    fgets(per.phone, sizeof(per.phone), stdin);
    per.phone[strlen(per.phone) - 1] = '\0';

    FILE *fp = fopen("1.bin", "w");
    if (NULL == fp)
    {
        printf("open error\n");
        return 1;
    }

    fwrite(&per, sizeof(per), 1, fp);
    //参数1 要写入内容的指针
    //参数2 一个元素的大小 字节数
    //参数3 要传入几个元素
    //参数4 写入的文件
    fclose(fp);
    return 0;
}