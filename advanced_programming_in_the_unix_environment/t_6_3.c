#include "apue.h"
#include <sys/utsname.h>

int main(void)
{
    struct utsname *name;
    if (uname(name) < 0)
    {
        err_sys("error uname");
    }

    printf("sysname:%s, nodename:%s, release:%s, version:%s, machine:%s\n", name->sysname, name->nodename, name->release, name->version, name->machine);
}