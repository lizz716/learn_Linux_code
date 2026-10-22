/*
           S_ISREG(m)  is it a regular file?

           S_ISDIR(m)  directory?

           S_ISCHR(m)  character device?

           S_ISBLK(m)  block device?

           S_ISFIFO(m) FIFO (named pipe)?

           S_ISLNK(m)  symbolic link?  (Not in POSIX.1-1996.)

           S_ISSOCK(m) socket?  (Not in POSIX.1-1996.)
==========================================================================
           S_ISUID     04000   set-user-ID bit
           S_ISGID     02000   set-group-ID bit (see below)

           S_ISVTX     01000   sticky bit (see below)

           S_IRWXU     00700   owner has read, write, and execute permission
           S_IRUSR     00400   owner has read permission
           S_IWUSR     00200   owner has write permission
           S_IXUSR     00100   owner has execute permission

           S_IRWXG     00070   group has read, write, and execute permission
           S_IRGRP     00040   group has read permission
           S_IWGRP     00020   group has write permission
           S_IXGRP     00010   group has execute permission

           S_IRWXO     00007   others  (not  in group) have read, write, and
                               execute permission
           S_IROTH     00004   others have read permission
           S_IWOTH     00002   others have write permission
           S_IXOTH     00001   others have execute permission

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <dirent.h>
int main(int argc, char **argv)
{
    DIR *dir = opendir(".");  // . 是当前文件
    if (NULL == dir)
    {
        fprintf(stderr, "opendir error\n");
        return 1;
    }
    while (1)
    {
        struct dirent *info = readdir(dir);
        if (NULL == info)
        {
            break;
        }
        char *filename = info->d_name;
        struct stat st;

        int ret = stat(filename, &st);
        if (-1 == ret)
        {
            printf("stat error\n");
            return 1;
        }
        // printf("ino: %lu,mode: %d,link: %lu,uid: %d,gid: %d,size: %lu,tm: %lu\n", st.st_ino, st.st_mode, st.st_nlink,
        //       st.st_uid, st.st_gid, st.st_size, st.st_mtim.tv_sec);
        if (S_ISREG(st.st_mode))
        {
            fputc('-', stdout);  // stdout 标准输出
        }
        else if (S_ISDIR(st.st_mode))
        {
            fputc('d', stdout);
        }
        else if (S_ISCHR(st.st_mode))
        {
            fputc('c', stdout);
        }
        else if (S_ISBLK(st.st_mode))
        {
            fputc('b', stdout);
        }
        else if (S_ISFIFO(st.st_mode))
        {
            fputc('p', stdout);
        }

        else if (S_ISLNK(st.st_mode))
        {
            fputc('l', stdout);
        }
        else if (S_ISSOCK(st.st_mode))
        {
            fputc('s', stdout);
        }
        //========================================
        if (S_IRUSR & st.st_mode)
        {
            printf("r");
        }
        else
        {
            printf("-");
        }
        if (S_IWUSR & st.st_mode)
        {
            printf("w");
        }
        else
        {
            printf("-");
        }
        if (S_IXUSR & st.st_mode)
        {
            printf("x");
        }
        else
        {
            printf("-");
        }
        //========================================
        if (S_IRGRP & st.st_mode)
        {
            printf("r");
        }
        else
        {
            printf("-");
        }
        if (S_IWGRP & st.st_mode)
        {
            printf("w");
        }
        else
        {
            printf("-");
        }
        if (S_IXGRP & st.st_mode)
        {
            printf("x");
        }
        else
        {
            printf("-");
        }
        //=====================================================
        if (S_IROTH & st.st_mode)
        {
            printf("r");
        }
        else
        {
            printf("-");
        }
        if (S_IWOTH & st.st_mode)
        {
            printf("w");
        }
        else
        {
            printf("-");
        }
        if (S_IXOTH & st.st_mode)
        {
            printf("x");
        }
        else
        {
            printf("-");
        }
        //==================================================
        struct tm *tminfo = localtime(&st.st_mtim.tv_sec);
        printf(" %lu %d %d  %5lu  %d月 %d  %02d:%02d %s\n", st.st_nlink, st.st_uid, st.st_gid, st.st_size,
               tminfo->tm_mon + 1, tminfo->tm_mday, tminfo->tm_hour, tminfo->tm_min, filename);
    }
    return 0;
}