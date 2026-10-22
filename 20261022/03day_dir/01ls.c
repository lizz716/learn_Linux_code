/* 目录遍历     目录不能改动
DIR *opendir(const char *name);

struct dirent *readdir(DIR *dirp); 结束返回NULL
 struct dirent {
               ino_t          d_ino;                //Inode number
               off_t          d_off;                //Not an offset; see below
               unsigned short d_reclen;             // Length of this record
               unsigned char  d_type;      文件类型  // Type of file; not supported
                                                    // by all filesystem types
               char           d_name[256]; 文件名    //Null-terminated filename
           };

d_type ：

DT_BLK      This is a block device. |存储类设备 硬盘

DT_CHR      This is a character device. |字符类设备 鼠标键盘

DT_DIR      This is a directory.  |目录

DT_FIFO     This is a named pipe (FIFO). |命名管道 通信方式

DT_LNK      This is a symbolic link. |软链接或符号链接 类似win桌面的快捷方式

DT_REG      This is a regular file.  |一般文件、普通文件 a.out .o .c 照片

DT_SOCK     This is a UNIX domain socket.  |套接字 网络相关文件

DT_UNKNOWN  The file type could not be determined. |不认识 别的系统的特有文件

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
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
        switch (info->d_type)
        {
            case DT_DIR:
                printf("目录文件：");
                break;
            case DT_REG:
                printf("普通文件：");
                break;
            case DT_BLK:
                printf("块设备：");  // dev
                break;
            default:
                printf("其他文件 :");
                break;
        }
        
        printf("%s\n", info->d_name);
    }
    closedir(dir);

    return 0;
}