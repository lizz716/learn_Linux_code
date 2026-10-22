#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
    int ret = chdir("../");  //成功返回0，失败返回-1
    if(-1 == ret)
    {
        
        fprintf(stderr,"chdir error\n");
        return 1;
    }
    FILE *fp = fopen("new","w");
    fclose(fp); 

    return 0;
}
