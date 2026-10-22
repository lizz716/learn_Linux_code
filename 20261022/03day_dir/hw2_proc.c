#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int is_all_num(char *s)
{
    if (NULL == s)
    {
        printf("s error\n");
        return -1;
    }
    
    while (*s != '\0')
    {
        if (*s < '0' || *s > '9')
        {
            return 0;
        }
        ++s;
    }
    return 1;
}

int main(int argc, char **argv)
{
    DIR *dir = opendir("/proc");
    if (NULL == dir)
    {
        fprintf(stderr, "opendir error\n");
        return 1;
    }
    int num = 0;
    while (1)
    {
        struct dirent *info = readdir(dir);
        if (NULL == info)
        {
            break;
        }
        if (info->d_type == DT_DIR && is_all_num(info->d_name) == 1)
        {
            num++;
        }
    }
    closedir(dir);
    printf("%d\n", num);
    return 0;
}