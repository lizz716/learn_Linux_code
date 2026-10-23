#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

//bmp是小端，数据从后往前有效
int getBiWidth(char *picture)
{
    int fd = open(picture, O_RDONLY);
    if (-1 == fd)
    {
        printf("open error\n");
        return -1;
    }

    unsigned char buf[4] = {0};

    off_t st = lseek(fd, 18, SEEK_SET);
    int ret = read(fd, buf, 4);
    if (-1 == st || -1 == ret)
    {
        perror("lseek read error\n");
        return -1;
    }
    close(fd);
    int biWidth = (int)buf[0] | (int)buf[1] << 8 | (int)buf[2] << 16 | (int)buf[3] << 24;
    return biWidth;
}

int getBiHeight(char *picture)
{
    int fd = open(picture, O_RDONLY);
    if (-1 == fd)
    {
        printf("open error\n");
        return -1;
    }

    unsigned char buf[4] = {0};

    off_t st = lseek(fd, 22, SEEK_SET);
    int ret = read(fd, buf, 4);
    if (-1 == st || -1 == ret)
    {
        perror("lseek read error\n");
        return -1;
    }
    close(fd);
    int Height = (int)buf[0] | (int)buf[1] << 8 | (int)buf[2] << 16 | (int)buf[3] << 24;
    return Height;
}


int getBpp(char *picture)
{
    int fd = open(picture, O_RDONLY);
    if (-1 == fd)
    {
        printf("open error\n");
        return -1;
    }

    unsigned char buf[2] = {0};

    off_t st = lseek(fd, 28, SEEK_SET);
    int ret = read(fd, buf, 2);
    if (-1 == st || -1 == ret)
    {
        perror("lseek read error\n");
        return -1;
    }
    close(fd);
    int BPP = (int)buf[0] | (int)buf[1] << 8;
    return BPP;
}

int isBmp(char *picture)
{
    int fd = open(picture, O_RDONLY);
    if (-1 == fd)
    {
        printf("open error\n");
        return -1;
    }

    unsigned char buf[2] = {0};

    int ret = read(fd, buf, 2);
    close(fd);

    if (buf[0] == 'B' && buf[1] == 'M')
    {
        return 1;
    }

    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("uasge :./a.out  picture\n");
        return 1;
    }
    if (!isBmp(argv[1]))
    {
        printf("pls input bmp\n");
        return 1;
    }
    int biWidth = getBiWidth(argv[1]);
    printf("biWidth :%d\n", biWidth);
    int Height = getBiHeight(argv[1]);
    printf("Height :%d\n", Height);
    int bpp = getBpp(argv[1]);
    printf("bpp :%d\n", bpp);
    return 0;
}
