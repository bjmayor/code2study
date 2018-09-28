#include <stdio.h>
#include <string.h>
int lower(int c);
main()
{
    char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    for (i=0;i<strlen(str);i++)
    {
        printf("%c",lower(str[i]));
    }
}


int lower(int c)
{
    return (c >='A' && c<='Z') ?  (c + 'a'-'A') : c;
}