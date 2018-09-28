#include <stdio.h>
#define TABSPACE 8
main()
{
    char c;
    int position=0;
    int fillspace = 0;
    while ((c=getchar())!=EOF)
    {
        if (c=='\t')
        {
            fillspace = TABSPACE - position;
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