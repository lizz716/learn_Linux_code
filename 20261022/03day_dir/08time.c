#include<stdio.h>
#include<time.h>
int	main(int argc, char **argv)
{
    time_t tm = time(NULL);
    printf("%lu\n",tm);
    

    return 0;
}
