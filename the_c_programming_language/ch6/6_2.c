#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORD 100
#define PREWORD 6
struct key {
    char *word;
    struct key *next;
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

struct tnode
{
    char *startword;
    struct key *keyword;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int );

void treeprint(struct tnode *);

#define NKEYS (sizeof(keytab)/sizeof(keytab[0]))

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

main(int argc, char **argv)
{
    char word[MAXWORD];
    struct key *p;
    struct tnode *root;
    int preword = PREWORD;

    root = NULL;

    if (argc>1 && atoi(argv[1])>0)
    {
        preword = atoi(argv[1]);
    }
    while (getword(word, MAXWORD) !=EOF)
    {
        if (isalpha(word[0]))
        {
            if((p = binsearch(word, keytab, NKEYS))==NULL)
            {
                root = addtree(root, word, preword);
            }
        }
    }

    treeprint(root);

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

struct tnode *talloc(void);
struct key *kalloc(void);
//char *strdup(char *);

struct tnode *addtree(struct tnode *p, char *w, int preword)
{
    int cond;
    struct key *temp;
    char word[MAXWORD];
    strncpy(word,w,preword);
    word[preword] = '\0';
    if (p==NULL)
    {
        p = talloc();
        p->startword = strdup(word);
        p->left = p->right = NULL;
        p->keyword = kalloc();
        p->keyword->word = strdup(w);
        p->keyword->next  = NULL;
    }
    else if((cond = strcmp(word, p->startword))==0)
    {
        temp = p->keyword;            
        while (temp->next  != NULL && strcmp(temp->word,w)!=0)
        {
            temp = temp->next;
        }
        if (temp->next == NULL && strcmp(temp->word,w)!=0)
        {
            temp->next = kalloc();
            temp->next->word = strdup(w);
            temp->next->next = NULL;

        }
    }
    else if(cond < 0)
    {
        p->left = addtree(p->left, w, preword);
    }
    else
    {
        p->right = addtree(p->right, w, preword);
    }
    return p;
}

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

struct key *kalloc(void)
{
    return (struct key *) malloc(sizeof(struct key));
}

/*
   char *strdup(char *s)
   {
   char *p;
   p = (char*)malloc(strlen(s)+1);
   if (p!=NULL)
   {
   strcpy(p, s);
   }
   return p;
   }
   */

void treeprint(struct tnode *p)
{
    struct key *temp;
    if (p!=NULL)
    {
        treeprint(p->left);

        temp = p->keyword;            
        int i=0;
        while (temp  != NULL)
        {
            printf("%s ",temp->word );
            temp = temp->next;
        }

        printf("\n");
        printf("\n");
        treeprint(p->right);
    }
}
