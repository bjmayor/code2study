#include <stdio.h>
#define MAXLINE 1000
int mygetline(char line[], int maxline);
void copy(char to[], char from[]);
main()
{
    int len;
    int max;
    char line[MAXLINE];

    max=0;
    while ((len=mygetline(line,MAXLINE))>0)
    {
        if (len > 0)
        {
            printf("%s",line);
        }

        if (len==(MAXLINE-1) && line[MAXLINE-2]!='\n')
        {
            max += len;
        }
        else
        {
            if (max == 0)
            {
                max = len;
            }
            else
            {
                max += len;
            }
            printf("%d\n",max);
            max = 0;
        }

    }
    return 0;
}

int mygetline(char s[], int lim)
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

void copy(char to[], char from[])
{
    int i=0;
    while ((to[i]=from[i])!='\0')
    {
        ++i;
    }

}
