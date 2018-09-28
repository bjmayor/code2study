#include <stdio.h>
#include <string.h>
#define MAX 1024
#define abs(s) (s)>0?(s):-(s)
void reverse(char s[],int len);
void itoa(int n, char s[]);
main()
{
    int test = -2147483648;
    char str[MAX];
    itoa(test,str);
    printf("%d, to str is:%s\n",test,str);
}
void itoa(int n, char s[])
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
    s[i] = '\0';
    reverse(s,strlen(s));
}
void reverse(char s[],int len)
{
    char c;
    if (len>1)
    {
        c = s[0];
        s[0] = s[len-1];
        s[len-1] = c;
        reverse(s+1,len-2);
    }
    
}

