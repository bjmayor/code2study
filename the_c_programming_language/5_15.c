#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#define REVERT 1
#define MAXLINES 5000
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int revert);

int numcmp(char *, char *);
int mystrncmp(char *, char *);

int main(int argc, char **argv)
{
    int nlines;
    int numeric = 0;
    int revert = 0;
    int casesensive = 1;
    int c;

    while ( --argc > 0 && (*++argv)[0]=='-')
    {
        while( c = *++argv[0])
        {
            switch (c)
            {
                case 'r':
                    revert = REVERT;
                    break;
                case 'n':
                    numeric = 1;
                    break;
                case 'f':
                    casesensive = 0;
                break;
                default:
                    printf("sort: illegal option %c\n",c);
                    revert = 0;
                    numeric = 0;
                    casesensive = 1;
                    break;
            }
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >=0)
    {
        myqsort((void **)lineptr,0,nlines-1, (int (*)(void *,void *))(numeric ? numcmp : (casesensive==1?strcmp:mystrncmp)), revert);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("erorr: input too big to deal\n");
        return 1;
    }
    return 0;
}

#define MAXLEN 1000
int mygetline(char *,int);
char *alloc(int);
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len-1] = '\0';//删除换行符
            strcpy(p,line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;

}

void myqsort(void *v[], int left, int right, int (*comp)(void *,void *), int revert)
{
    int i,last;
    void swap(void *v[], int ,int);

    if (left >= right)
    {
        return ;
    }

    swap(v,left, (left+right)/2);
    last = left;
    for (i = left+1;i<= right; i++)
    {
        if (revert)
        {
            if ((*comp)(v[i], v[left]) > 0 )
            {
                swap(v,++last,i);
            }

        }
        else
        {
            if ((*comp)(v[i], v[left]) < 0 )
            {
                swap(v,++last,i);
            }

        }
    }
    swap(v, left, last);
    myqsort(v, left, last-1, comp,revert);
    myqsort(v, last+1, right, comp,revert);
}




int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
    {
        return -1;
    }
    else if (v1 > v2)
    {
        return 1;
    }
    return 0;
}

void swap(void *v[], int i,int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i=0; i< nlines; i++)
    {
        printf("%s\n",lineptr[i]);
    }
}

int mystrncmp(char *s, char *t)
{
    int c,g;
    while ((c=tolower(*s++))!='\0' && (g=tolower(*t++))!='\0')
    {
        if(c==g)
        {
            continue;
        }
        else
        {
            if (c>g)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
    return 0;
}
