#include <stdio.h>
int strrindex(char s[], char t[]);
main()
{
    char t1[] = "helloworld,world";
    char t2[] = "world";
    printf("expected is 11,result is %d\n",strrindex(t1,t2));
}
int strrindex(char s[], char t[])
{
    int i,j,k;
    int found=-1;
    for (i=0; s[i]!='\0';i++)
    {
        for (j=i,k=0; t[k]!='\0' && s[j]==t[k];j++,k++)
            ;
        if(k>0 && t[k]=='\0')
        {
            found = i;
        }
    }
    return found;
}