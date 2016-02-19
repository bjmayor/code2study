#include <stdio.h>
#define MAXLINE 80
#define INLINE 1
#define OUTLINE 0
int mygetline(char line[], int maxline);
void copy(char to[], char from[]);
main()
{
    int len;
    int max;
    int isInLine;
    char line[MAXLINE];

    max=0;
    isInLine = OUTLINE;
    while ((len=mygetline(line,MAXLINE))>0)
    {

        if (len==(MAXLINE-1) && line[MAXLINE-2]!='\n')
        {
            isInLine = INLINE;
            printf("%s",line);
        }
        else
        {
            if (len > 0 && isInLine==INLINE)
            {
                printf("%s",line);
            }

            isInLine = OUTLINE;
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
