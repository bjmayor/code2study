#include <stdio.h>
main()
{
    int c, n1, t1, s1;
    n1 = t1 = s1 = 0;
    while ((c = getchar()) !=EOF)
    {
        if (c == '\n')
            ++n1;
        else if (c == '\t')
            ++t1;
        else if (c == ' ')
            ++s1;
    }
    printf("%d %d %d\n", s1, t1, n1);


}

