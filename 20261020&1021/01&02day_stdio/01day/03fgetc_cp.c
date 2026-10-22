#include <stdio.h>

int main(int argc, char **argv)
{
  //   FILE *dstfp = fopen("2.txt", "w");
  //   FILE *srcfp = fopen("1.txt", "r");

  FILE *dstfp = fopen("2 pig.png", "w");
  FILE *srcfp = fopen("/home/linux/1.png", "r");

  if (NULL == dstfp || NULL == srcfp)
  {
    printf("fopen error\n");
    return 1;
  }

  while (1)
  {
    int c = 0;
    c = fgetc(srcfp);
    if (EOF == c)
    {
      break;
    }
    fputc(c, dstfp);
  }

  fclose(srcfp);
  fclose(dstfp);

  return 0;
}

