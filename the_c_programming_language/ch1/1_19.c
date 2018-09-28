#include <stdio.h>
#define MAXLINE 10
int mygetline(char line[], int maxline);
void reverse(char s[]);
void copy(char to[],char from[]);
main()
{
    int len;
    char line[MAXLINE];

    while ((len=mygetline(line,MAXLINE))>0)
    {
        reverse(line);
        printf("%s",line);

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

void reverse(char str[])
{
    int i=0;
    int len;
    char temp[MAXLINE];
    copy(temp, str);
    for(i=0; str[i]!='\0'; i++);
   len=i; 
    for(i=0;i<len;i++)
    {
        str[i]=temp[len-1-i];
    }

}
void copy(char to[],char from[])
{
    int i=0;
    while ((to[i]=from[i])!='\0')
    {
        ++i;
    }

}
