#include <stdio.h>
void squeeze(char s[], char t[]);
main()
{
    char s[] = "3209jXfdsafAf2";
    printf("before is :%s\n",s);
    squeeze(s,"0123456789");
    printf("after is :%s\n",s);
}

void squeeze(char s[], char t[])
{
    int i, j,k;

    for (k=0; t[k]!='\0'; k++)
    {
        for (i = j =0; s[i]!='\0';i++)
        {
            if (s[i] !=t[k])
            {
                s[j++] = s[i];
            }
        }
        s[j] ='\0';
    }
}