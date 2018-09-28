#include <stdio.h>
#include <string.h>
#define abs(s) ((s)>0?(s):-(s))
void itob(int n, char s[], int b);
void reverse(char s[]);

main()
{
    int test = 123;
    int b = 2;
    char s[1024];
    itob(test,s, b);
    printf("%d trans to %d is %s\n", test,b,s);
    itob(-test,s, b);
    printf("%d trans to %d is %s\n", -test,b,s);
}
void itob(int n, char s[], int b)
{
    int i=0;
    int sign = n;
    do{
        s[i++] = abs(n%b)+'0';
    } while((n/=b)!=0);
    if(sign < 0)
    {
        s[i++] = '-';
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

