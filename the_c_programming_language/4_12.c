#include <stdio.h>
#include <string.h>
#define MAX 1024
int itoa(int n, char s[],int index);
main()
{
    int test = -214748348;
    char str[MAX];
    itoa(test,str, 0 );
    printf("%d, to str is:%s\n",test,str);
}
int itoa(int n, char s[], int index)
{
    if (n < 0 )
    {
        s[index++] = '-';
        n = -n;
    }
    if (n/10)
    {
      index =  itoa(n/10,s,index);
    }
    s[index++] = n%10+'0';
    if (n<10)
    {
        s[index] = '\0';
    }
    return index;

}
