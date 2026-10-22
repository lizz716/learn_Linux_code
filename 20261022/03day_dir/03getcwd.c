#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char buf[512] = {0}; //存放路径
  
    getcwd(buf, sizeof(buf)); // pwd  将当前路径写入buf 
    printf("before cd :%s\n", buf);
   
    int ret = chdir("../");  //成功返回0，失败返回-1
    
    getcwd(buf, sizeof(buf));
    printf("after cd :%s\n", buf);

    return 0;
}
