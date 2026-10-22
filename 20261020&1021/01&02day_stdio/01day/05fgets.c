#include <stdio.h>
int main(int argc, char **argv)
{
  FILE *fp = fopen("1.txt", "r");
  if (NULL == fp)
  {
    printf("open error\n");
    return 1;
  }

  while (1)
  {
    char s[256] = {0};  //不能是指针，指针只有访问的功能，没有存储功能
    char *ret = NULL;
    ret = fgets(s, 5, fp);
    if (NULL == ret)
    {
      break;
    }
    printf("%s", s);
  }

  fclose(fp);
  return 0;
}
