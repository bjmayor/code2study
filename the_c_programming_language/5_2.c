#include <stdio.h>
#include <stype.h>

int getch(void);
void ungetch(int);

int getfloat(double *pn)
{
    int c,sign,power;

    while (isspace(c=getch()));
    if (!isdigit(c) && c!=EOF && c!='+' && c!='-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c=='-')?-1:1;
    if (c=='+' || c=='-')
    {
        c = getch();
    }

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c-'0');
    }

    if (c == '.')
    {
        c = getch();
    }

    for (power = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c-'0');
        power = 10 * power + (c-'0');
    }
    *pn /= power;
    *pn *= sign;
    if (c !=EOF)
    {
        ungetch(c);
    }

    return c;
    
}