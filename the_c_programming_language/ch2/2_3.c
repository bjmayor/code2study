#include <stdio.h>
int htoi(char s[]);
main()
{
    printf("%d\n",htoi("0xABD232"));
    printf("%d\n",htoi("0XABD232"));
    printf("%d\n",htoi("ABD232"));
    printf("%d\n",htoi("A"));
    printf("%d\n",htoi("9"));
}

int htoi(char s[])
{
    int r=0;
    int i=0;
    char c;
    while((c=s[i++])!='\0')
    {
        if(c>='a' && c<='f')
        {
            r= r *16+(c-'a')+10;
        }
        else if(c>='A' && c<='F')
        {
            r= r *16+(c-'A')+10;
        }
        else if(c>='0' && c<='9')
        {
            r= r *16+c-'0';
        }
        else if(c=='x' || c=='X')
        {
            r=0;
        }
    }
    return r;
}