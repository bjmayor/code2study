#include <stdio.h>
void mystrcat(char *s, char *t);
main()
{
    char t1[30] = "source";
    char *t2 = "target";
    printf("%s, %s",t1,t2);
    mystrcat(t1,t2);
    printf(" link is  %s\n ",t1);
}

void mystrcat(char *s, char *t)
{
    while(*s++);
    s--;
    while(*s++ = *t++);
}