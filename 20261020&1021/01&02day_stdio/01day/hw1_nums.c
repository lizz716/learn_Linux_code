#include <stdio.h>

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("uasge:./a.out filename\n");
    return 1;
  }

  int num[26] = {0};
  int i;

  FILE *fp = fopen(argv[1], "r");
  if (NULL == fp)
  {
    printf("open error\n");
    return 1;
  }

  while (1)
  {
    int c = fgetc(fp);
    if (EOF == c)
    {
      break;
    }

    if (c >= 'a' && c < 'z')
    {
      num[c - 'a']++;
    }
  }

  fclose(fp);

  for (i = 0; i < 26; ++i)
  {
    printf("%c: %d\n", i + 'a', num[i]);
  }
  return 0;
}
