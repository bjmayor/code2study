#include "apue.h"
#include <time.h>

int main(void)
{
    time_t *currenttime;
    struct tm *tm;

    char buf[1024];

    if (time(currenttime) == -1)
    {
        err_sys("time error");
    }

    if ((tm=localtime(currenttime)) != NULL)
    {
        if(strftime(buf, 1024, "%Y年 %m月%d日 %A %H时%M分%S秒 %Z", tm) !=0)
        {
            printf("%s\n", buf);
        }
    }
    exit(0); 
}