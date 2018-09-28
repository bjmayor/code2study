#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#define LASTLINES 10
#define MAXLINES 5000



char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void tail(int n, int total, char *lineptr[]);
int main(int argc, char **argv)
{
    int lastline = LASTLINES;
    int nlines;
    if(argc >1 && (*++argv)[0] == '-')
    {
        lastline = atoi(++(*argv));
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >=0)
    {
        tail(lastline,nlines, lineptr);
    }
    else
    {
        printf("erorr: input too big to deal\n");
        return 1;
    }
    return 0;
}
void tail(int n, int total, char *lineptr[])
{
    int begin = (total - n + 1) > 0 ? total-n + 1 : 1;
    while(begin <= total)
    {
        printf("%s\n",*(lineptr+begin-1));
        begin++;
    }
}

#define MAXLEN 1000
int mygetline(char *,int);
char *alloc(int);
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len-1] = '\0';//删除换行符
            strcpy(p,line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;

}

