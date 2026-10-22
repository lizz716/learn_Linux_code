#include <stdio.h>

int main(int argc, char **argv)
{
  //打开文件
  FILE *fp = fopen("1.txt", "r");
  if (fp == NULL)
  {
    printf("fopen error\n");
    return 1;
  }
  //读取文件
  while (1)
  {
    int c = fgetc(fp);
    // EOF为文件结束标志
    if (EOF == c)
    {
      break;
    }
    printf("%c", c);
  }
  putchar('\n');
  //关闭文件
  fclose(fp);
  return 0;
}