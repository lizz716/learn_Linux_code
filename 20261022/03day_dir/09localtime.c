#include <stdio.h>
#include <time.h>
int main(int argc, char **argv)
{
    time_t tm = time(NULL);
    printf("%lu\n", tm);
    struct tm *tminfo = localtime(&tm);
    printf("%d-%d-%d %d:%d:%d\n", tminfo->tm_year + 1900, tminfo->tm_mon + 1, tminfo->tm_mday, tminfo->tm_hour,
           tminfo->tm_min, tminfo->tm_sec);

    char *data = NULL;
    data = ctime(&tm);
    printf("%s", data);
    return 0;
}