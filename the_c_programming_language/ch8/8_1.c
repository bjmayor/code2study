#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int fd;
    void filecopy(int , int );
    char *prog = argv[0];

    if (argc == 1)
    {
        filecopy(0, 1);
    }
    else
    {
        while(--argc)
        {
            if ((fd=open(*++argv,O_RDONLY,0)) == -1)
            {
                fprintf(stderr, "%s: can't open %s\n",prog, *argv);
                exit(1);
            }
            else
            {
                filecopy(fd, 1);
                close(fd);
            }
        }
    }

    exit(0);
}

void filecopy(int ifd, int ofd)
{
    int n;
    char buf[BUFSIZE];
    while ((n = read(ifd, buf, BUFSIZE)) >0)
    {
        if(write(ofd, buf, n) !=n)
        {
            printf("write error\n");
        }
    }
}
