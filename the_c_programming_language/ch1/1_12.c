#include <stdio.h>
#define IN 1
#define OUT 0

main()
{
    int c, state,last;
    last = state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (last == IN)
            {
                putchar('\n');
            }
            last = state = OUT;
        }
        else if ( state == OUT)
        {
            last = state = IN;
            putchar(c);
        }
        else
        {
            putchar(c);
        }
    }
}

