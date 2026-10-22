#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    int ret = mkdir("new", 0777);

    if (-1 == ret)
    {
        fprintf(stderr, "mkdir error\n");
        return 1;
    }
    
    return 0;
}
