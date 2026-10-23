//显示当前目录下所有目录内的文件 递归
// .  .. 不能进

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int prinDir(char *dir)
{
    DIR *d = opendir(dir);
    struct dirent *info;
    int n = 1;
    while ((info = readdir(d)) != NULL)
    {
        if (strcmp(info->d_name, ".") == 0 || strcmp(info->d_name, "..") == 0)
        {
            continue;
        }
        printf("%s  ", info->d_name);
    }
    putchar('\n');
    putchar('\n');
    closedir(d);
    return 0;
}

int LS_R(char *dir)
{
    //打印当前目录路径 和 目录下的文件
    printf("%s:\n", dir);
    prinDir(dir);

//看是否递归

    DIR *d = opendir(dir);
    char path[4096] = {0};
    if (NULL == d)
    {
        fprintf(stderr, "opendir error\n");
        return 1;
    }
    struct dirent *info;
    while ((info = readdir(d)) != NULL)
    {
        if (strcmp(info->d_name, ".") == 0 || strcmp(info->d_name, "..") == 0)
        {
            continue;
        }

        if (strlen(dir) + 1 + strlen(info->d_name) >= sizeof(path))
        {
            continue;
        }//检查是否超限制
        //拼接路径
        strcpy(path, dir);
        strcat(path, "/");
        strcat(path, info->d_name);

        if (info->d_type == DT_DIR) //如果是目录就递归
        {
            LS_R(path);
        }
    }
    closedir(d);
    return 0;
}

int main(int argc, char **argv)
{
    
    LS_R(argv[1]);

    return 0;
}
