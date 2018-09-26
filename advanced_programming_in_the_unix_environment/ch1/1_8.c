#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR)
    {
        err_sys("signal error");
    }
    printf("%% ");
    while(fgets(buf, MAXLINE,stdin)!=NULL)
    {
        if (buf[strlen(buf)-1] == '\n')
        {
            buf[strlen(buf)-1] = 0;
        }

        if ((pid = fork()) < 0)
        {
            err_sys("fork error");
        }
        else if(pid == 0)
        {
            execlp(buf, buf, (char*)0);/*用新的程序文件替换原先执行的程序文件，正确的话，下面的二行代码不会执行*/
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        if ((pid = waitpid(pid, &status, 0)) < 0)
        {
            err_sys("waitpid error");
        }
        printf("%% ");
    }
}

void sig_int(int signo)
{
    printf("interrupt\n%%");
}