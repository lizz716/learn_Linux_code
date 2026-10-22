
/*
 struct stat {
               dev_t     st_dev;         ID of device containing file
               ino_t     st_ino;         Inode number
               mode_t    st_mode;         File type and mode
               nlink_t   st_nlink;        Number of hard links
               uid_t     st_uid;          User ID of owner
               gid_t     st_gid;          Group ID of owner
               dev_t     st_rdev;         Device ID (if special file)
               off_t     st_size;         Total size, in bytes        //常用
               blksize_t st_blksize;      Block size for filesystem I/O
               blkcnt_t  st_blocks;       Number of 512B blocks allocated
            struct timespec st_atim;  Time of last access
               struct timespec st_mtim;   Time of last modification
               struct timespec st_ctim;   Time of last status change

           #define st_atime st_atim.tv_sec      Backward compatibility
           #define st_mtime st_mtim.tv_sec
           #define st_ctime st_ctim.tv_sec
           };
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    struct stat st;
    int ret = stat("./01ls.c", &st);
    if (-1 == ret)
    {
        printf("stat error\n");
        return 1;
    }
    printf("ino: %lu,mode: %d,link: %lu,uid: %d,gid: %d,size: %lu,tm: %lu\n", st.st_ino, st.st_mode, st.st_nlink,
           st.st_uid, st.st_gid, st.st_size, st.st_mtim.tv_sec);

    return 0;
}
