#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int width;
    int height;
    int depth;
    int colortype;
} pngInfo;

int isPng(char *picture)
{
    int fd = open(picture, O_RDONLY);
    if (-1 == fd)
    {
        printf("open error\n");
        return -1;
    }
    char buf[8] = {0};
    read(fd, buf, 8);
    /*
    十六进制值：89 50 4E 47 0D 0A 1A 0A
    核心识别：中间50 4E 47对应ASCII码“PNG”，是文件类型的核心标识。
    作用：区分PNG与其他图像格式（如BMP、JPG），避免解析错误。
    */
    if (buf[1] == 0x50 && buf[2] == 0x4E && buf[3] == 0x47)
    {
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}

int getPngInfo(char *picture, pngInfo *info)
{
    if (isPng(picture) == 0)
    {
        printf("pls input .png\n");
        return -1;
    }

    unsigned char buf[25] = {0};

    int fd = open(picture, O_RDONLY);
    if (-1 == fd)
    {
        printf("open error\n");
        return -1;
    }
    lseek(fd, 8, SEEK_SET);
    int ret = read(fd, buf, 25);
    if (ret != 25)
    {
        printf("read error\n");
        close(fd);
        return -1;
    }

    if (buf[4] == 'I' && buf[5] == 'H' && buf[6] == 'D' && buf[7] == 'R')
    {
        info->width = buf[8] << 24 | buf[9] << 16 | buf[10] << 8 | buf[11];
        info->height = buf[12] << 24 | buf[13] << 16 | buf[14] << 8 | buf[15];
        info->depth = buf[16];
        info->colortype = buf[17];
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}

int pngBpp(int depth, int colortype)
{
    int c;
    switch (colortype)
    {
        case 0:
            c = 1;
            break;
        case 2:
            c = 3;
            break;
        case 3:
            c = 1;
            break;
        case 4:
            c = 2;
            break;
        case 6:
            c = 4;
            break;

        default:
            return -1;
    }

    return depth * c;
}

int main(int argc, char **argv)
{
    if (isPng(argv[1]) == 0)
    {
        printf("pls input .png\n");
        return -1;
    }
    pngInfo *info = malloc(sizeof(pngInfo));
    if (NULL == info)
    {
        printf("malloc error\n");
        return 1;
        
    }
    getPngInfo(argv[1], info);
    int bpp = pngBpp(info->depth, info->colortype);
    printf("width : %d\nheight : %d\nbpp :% d\n", info->width, info->height, bpp);
    free(info);

    return 0;
}
