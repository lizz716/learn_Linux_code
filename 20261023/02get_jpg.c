#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct
{
    int width;
    int height;
    int depth;
    int comp;
} info;
int isJpg(char *picture)
{
    int fd = open(picture, O_RDONLY);
    if (-1 == fd)
    {
        perror("open error\n");
    }
    unsigned char buf[2] = {0};
    int ret = read(fd, buf, 2);
    if (-1 == ret)
    {
        perror("read error\n");
        return -1;
    }
    if (buf[0] == 0xFF && buf[1] == 0xD8)
    {
        close(fd);
        return -1;
    }
    else
    {
        close(fd);
        return 0;
    }
}

int getInfo(char *picture, info *p)
{
    int fd = open(picture, O_RDONLY);
    if (-1 == fd)
    {
        return -1;
    }

    if (!isJpg(picture))
    {
        printf("pls input .jpg\n");
        return -1;
    }

    unsigned char buf[8] = {0};
    int pos = 2;
    int found = 0;
    int t;
    int len = 0;

    while (!found)
    {
        lseek(fd, pos, SEEK_SET);
        int ret = read(fd, buf, 2);
        
        if (ret != 2)
        {
            break;
        }

        if (buf[0] != 0xFF)
        {
            pos++;
            continue;
        }

        if (buf[1] == 0xFF)
        {
            pos++;
            continue;
        }

        t = buf[1];

        if (t == 0xD8 || t == 0xD9 || t == 0x01 || (t >= 0xD0 && t <= 0xD7))
        {
            pos += 2;
            continue;
        }
        
        if (t == 0xDA)
        {
            break;
        }

        lseek(fd, pos + 2, SEEK_SET);
        ret = read(fd, buf, 2);
        if (ret != 2)
            break;

        len = (buf[0] << 8 | buf[1]);
        if (len < 2)
            break;

        if (t >= 0xC0 && t <= 0xCF && t != 0xC4 && t != 0xC8 && t != 0xCC)
        {
            lseek(fd, pos + 4, SEEK_SET);
            read(fd, buf, 6);
            p->depth = buf[0];
            p->height = (buf[1] << 8) | buf[2];
            p->width = (buf[3] << 8) | buf[4];
            p->comp = buf[5];
            found = 1;
            break;
        }
        pos += len + 2;
    }
    close(fd);
    return found;
}

int main(int argc, char **argv)
{
    if (!isJpg(argv[1]))
    {
        printf("pls input .jpg\n");
        return -1;
    }
    info *picture = malloc(sizeof(info));

    if (0 == getInfo(argv[1], picture))
    {
        printf("get info error\n");
    }
    else
    {
        printf("width : %d\nheigh : %d\nbpp : %d\n", picture->width, picture->height, picture->depth * picture->comp);
    }
    free(picture);
    return 0;
}
