#include "apue.h"
#include <signal.h>>

static void sig_int(int);

int main(void)
{
    sigset_t newmask, oldmask, zeromask;
    if (signal(SIGINT, sig_int) == SIG_ERR)
    {
        err_sys("signal(SIGINT) error");
    }

    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);

    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    {
        err_sys("SIG_BLOCK error");
    }

    pr_mask("in critical region: ");

    if (sigsuspend(&zeromask) != -1)
    {
        err_sys("sigsuspend error");
    }

    pr_mask("after return from sigsuspend: ");

    if (sigprocmask(SIG_SETMASK, &oldmask, NULL)<0)
    {
        err_sys("SIG_SETMASK error");
    }

    exit(0);
}

static void sig_int(int signo)
{
    pr_mask("\nin sig_int: ");
    return;
}