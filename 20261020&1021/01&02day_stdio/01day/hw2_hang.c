#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("uasge:./a.out filename\n");
    return 1;
  }

  int row_num = 0;
  FILE *fp = fopen(argv[1], "r");
  if (NULL == fp)
  {
    printf("open error\n");
    return 1;
  }

  while (1)
  {
    char buf[256] = {0};
    if (NULL == fgets(buf, sizeof(buf), fp))
    {
      break;
    }
    if ('\n' == buf[strlen(buf) - 1])
    {
      row_num++;
    }
  }
  row_num++;
  fclose(fp);
  printf("row : %d\n", row_num);

  return 0;
}
