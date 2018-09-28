#include <stdio.h>
#define MAX 1024
void escape(char s[],char t[]);
void unescape(char s[],char t[]);
main()
{
    char line[MAX];
    char escapestr[MAX];
    char unescapestr[MAX];
    int i=0;
    int c;
    while((c=getchar())!=EOF && i<MAX-1)
    {
        line[i++]  = c;
    }
    line[i] = '\0';
    printf("input string %s\n",line);
    escape(escapestr, line);
    printf("escape string %s\n",escapestr);
    unescape(unescapestr, escapestr);
    printf("unescape string %s\n",unescapestr);
}
void escape(char s[],char t[])
{
    int i=0;
    int j=0;
    int c;
    while((c=t[i])!='\0')
    {
        switch (c)
        {
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }
    s[j]='\0';
}
void unescape(char s[],char t[])
{
    int i=0;
    int j=0;
    int c;
    int isescape=0;
    while((c=t[i])!='\0')
    {
        switch (c)
        {
            case '\\':
                s[j++]='\\';
                isescape = 1;
                break;
            case 'n':
                if (isescape)
                {
                    s[j-1]='\n';
                }
                else
                {
                    s[j++] = 'n';
                }
                isescape=0;
                break;
            case 't':
                if (isescape)
                {
                    s[j-1]='\t';
                }
                else
                {
                    s[j++] = 't';
                }
                isescape=0;
                break;
            default:
                s[j++] = t[i];
                isescape=0;
                break;
        }
        i++;
    }
    s[j]='\0';

}
