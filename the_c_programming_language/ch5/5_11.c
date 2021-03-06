#include <stdio.h>
#include <stdlib.h>
#define TABSPACE 8

void detab(int stop);

int main(int argc, char **argv)
{
    int stop = TABSPACE;
    if ( argc >1 && atoi(*++argv)>0)
    {
        stop = atoi(*argv);
    }
    detab(stop);
}


void detab(int stop)
{
    char c;
    int position=0;
    int fillspace = 0;
    while ((c=getchar())!=EOF)
    {
        if (c=='\t')
        {
            fillspace = stop - position;
            while(fillspace--)
            {
                putchar(' ');
            }
            position=0;
        }
        else if (c=='\n')
        {
            position = 0;
        }
        else
        {
            putchar(c);
            position++;
        }
    }

}
