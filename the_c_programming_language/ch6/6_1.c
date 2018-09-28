#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD 100
struct key {
    char *word;
    int count;
} keytab[] = {
    "auto",0,
    "break",0,
    "case",0,
    "char",0,
    "const",0,
    "continue",0,
    "default",0,
    "double",0,
    "float",0,
    "int", 0,
    "long",0,
    "unsigned",0,
    "void",0,
    "volatile",0,
    "while",0

};

#define NKEYS (sizeof(keytab)/sizeof(keytab[0]))

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

main()
{
    char word[MAXWORD];
    struct key *p;
    char *temp = "break break break break";

    while (getword(word, MAXWORD) !=EOF)
    {
        if (isalpha(word[0]))
        {
            if((p = binsearch(word, keytab, NKEYS))!=NULL)
            {
                p->count++;
            }
        }
    }

    for (p = keytab; p < keytab+NKEYS; p++)
    {
        if (p->count >0)
        {
            printf("%4d %s\n",p->count, p->word);
        }
    }
    return 0;
}

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c = getch()))
        ;
    if (c!=EOF)
        *w++ = c;

    if (isalpha(c))//类型和变量
    {
        for (;--lim > 0; w++)
        {
            if (!isalnum(*w = getch()) && *w!='_')
            {
                ungetch(*w);
                break;
            }
        }

        *w = '\0';
        return word[0];

    }
    else
    {
        switch(c)
        {
            case '/'://注释
                *w++ = getch();
                if(*w != EOF)
                {
                    if (*w == '/')//行级注释
                    {
                        while((*w=getch())!=EOF)
                        {
                            if(*w=='\n')
                            {
                                break;
                            }
                            w++;
                        }
                        *++w = '\0';
                        return c;
                    }
                    else if(*w == '*')//多行注释
                    {
                        for(;(*w = getch())!=EOF;w++)
                        {
                            if (*w == '/' && *(w-1)=='*')
                            {
                                *++w = '\0';
                                return c;
                            }
                            w++;
                        }

                    }
                }
                else
                {
                    *w = '\0';
                }
                return c;
            case '#'://条件编译or宏
                while((*w=getch())!=EOF)
                {
                    if ( *w == '\n')
                    {
                        break;
                    }
                    w++;
                }
                *++w = '\0';
                return c;
            case '\'':
                *w++ = getch();
                *w++ = getch();
                *++w = '\0';
                return c;

            case '"'://常量字符串
                for(;(*w = getch())!=EOF;w++)
                {
                    if (*w == '"' && *(w-1)!='\\')
                    {
                        *++w = '\0';
                        break;
                    }
                }
                return c;
            default:
                *w = '\0';
                return c;
        }
    }

}


struct key *binsearch(char *word, struct key *tab, int n)
{
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high)
    {
        mid = low + (high-low)/2;
        if ((cond = strcmp(word, mid->word)) < 0)
        {
            high = mid;
        }
        else if(cond>0)
        {
            low = mid+1;
        }
        else
        {
            return mid;
        }

    }
    return NULL;

}
