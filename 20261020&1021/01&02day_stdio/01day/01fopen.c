#include <stdio.h>

int main(int argc, char **argv)
{
  // 1、打开文件
  FILE *fp = fopen("1.txt", "w");
  if (fp == NULL)
  {
    printf("fopen error\n");
    return 1;
  }
  
  // 2、写文件
  fputc('o', fp);
  fputc('k', fp);

  // 3、关闭文件
  fclose(fp);

  return 0;
}
