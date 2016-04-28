#include "apue.h"

int glob = 6;

int main(void)
{
    int var;
    int i;
    char buf[1024];
    pid_t pid;

    var = 88;

    printf("before vfork\n");

    if ((pid = vfork()) < 0)
    {
        err_sys("vfork error");
    }
    else if (pid == 0)
    {
        glob++;
        var++;
        fclose(stdout);
        exit(0);
    }

    i = printf("pid = %d, glob=%d, var=%d\n", getpid(), glob, var);
    sprintf(buf, "%d\n", i);
    write(STDOUT_FILENO, buf, strlen(buf));
    exit(0);
}
