#include <stdio.h>
main()
{
    int c, c1=EOF;
    while ((c=getchar()) != EOF)
    {
        if (c1==' ' && c==' ')
           continue;
        putchar(c);
        c1 = c;
    }
}

