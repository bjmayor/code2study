#include <stdio.h>
int  any(char s[], char t[]);
main()
{
    char s[] = "fdsif889fjio";
    char t[] = "xx98";
    printf("%s-%s any is:%d\n",s,t,any(s,t));
}

int  any(char s[], char t[])
{
    int position = -1;
    int i,j;
    for (i=0; t[i]!='\0';i++)
    {
        for (j=0; s[j]!='\0';j++)
        {
            if (s[j]==t[i])
            {
                if (position == -1)
                {
                    position = j;
                }
                else  if (j < position)
                {
                    position = j;
                }
            }
        }
    }
    return position;
}