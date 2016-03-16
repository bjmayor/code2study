#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int mygetline(char *s, int lim)
{
    int c,i;

    for (i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i++] = '\n';
    }
    s[i] = '\0';
    return i;
}
