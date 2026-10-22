#include <stdio.h>
int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("uasge:./a.out filename\n");
    return 1;
  }

  char *file = argv[1];
  FILE *fp = fopen(file, "r");

  if (NULL == fp)
  {
    printf("open error\n");
    return 1;
  }

  while (1)
  {
    char s[256] = {0};
    char *ret = NULL;  //用来接收fgets的返回值，判断是否读完
    ret = fgets(s, 5, fp);
    if (NULL == ret)
    {
      break;
    }
    printf("%s", s);
  }

  return 0;
}
