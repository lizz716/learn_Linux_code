#include <stdio.h>
int main(int argc, char **argv)
{
  FILE *fp = fopen("1.txt", "w");

  if (NULL == fp)
  {
    printf("open error\n");
    return 1;
  }

  fputs("hello  world\n", fp);

  char buf[256] = "你好\n";  // 7 byte 一个汉字3字节 在linux下
  fputs(buf, fp);

  fclose(fp);

  return 0;
}
