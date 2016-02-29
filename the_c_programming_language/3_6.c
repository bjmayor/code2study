#include <stdio.h>
#include <string.h>
#define MAX 1024
#define abs(s) (s)>0?(s):-(s)
void reverse(char s[]);
void itoa(int n, char s[],int minWidth);
main()
{
    int test = -2;
    char str[MAX];
    itoa(test,str,10);
    printf("%d, to str is:%s\n",test,str);
}
void itoa(int n, char s[],int minWidth)
{
    int i, sign=n;
    i = 0;
    do {
        s[i++] = abs(n%10) + '0';
    }
    while((n/=10)!=0);

    if (sign < 0)
    {
        s[i++] = '-';
    }
    while(i<minWidth)
    {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}
void reverse(char s[])
{
    int i,j;
    int c;
    for (i=0,j=strlen(s)-1; i<j;i++,j--)
    {
        c=s[i],s[i] = s[j],s[j]=c;
    }
}
