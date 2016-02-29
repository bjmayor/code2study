#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 1024
#define TRUE 1
#define FALSE 0
void expand(char s1[], char s2[]);
main()
{
    char s[] = "test a-z and A-Z , a-Z, 0-9 , a-b-c -0-3";
    char result[MAX];

    printf("origin string is:%s\n",s);
    expand(s,result);
    printf("expand string is:%s\n",result);
}

void expand(char s1[], char s2[])
{
    int i,j=0;
    int c;
    int maybeExpand = FALSE;
    for (i=0;i<strlen(s1);i++)
    {
        c = s1[i];
        if(c == '-')
        {
            if(i==0)
            {
                s2[j++] = '-';
            }
            else
            {
                if(!isalnum(s1[i-1]))
                {
                    s2[j++] = c;
                    maybeExpand = FALSE;
                }
                else
                {
                    maybeExpand = TRUE;
                    s2[j++] = c;
                }
            }
        }
        else
        {
            if(maybeExpand)
            {
                int before = s1[i-2];
                if((before>='0' && before<='9' && c>='0' && c<='9')
                   || (before>='a' && before<='z' && c>='a' && c<='z')
                   || (before>='A' && before<='Z' && c>='A' && c<='Z'))
                {
                    int number = c-before; 
                    if(number>0)
                    {
                        j--;
                        for(int k=1;k<=number;k++)
                        {
                            s2[j++]  = before+k;
                        }
                    }
                }
                else
                {
                    s2[j++] = c;
                    maybeExpand = FALSE;
                }
            }
            else
            {
                s2[j++] = c;
            }
        }
    }
    s2[j] = '\0';
}
