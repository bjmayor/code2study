#include <stdio.h>
#include <stdarg.h>
int minscanf(char *fmt, ...);
main()
{
    int d;
    float f;
    int match;
    if(2==(match=minscanf(" %d  %f",&d,&f)))
    {
        printf("match ok %d %f\n",d, f);
    }
    else
    {
        printf("match error, expetec 2, only %d\n", match);
    }

}
int minscanf(char *fmt, ...)
{
    va_list ap;
    char c;
    char *p, *sval;
    char *cval;

    int matchcount = 0;
    int *ival;
    float *fval;

    va_start(ap ,fmt);
    
    for (p=fmt; *p; p++)
    {
        if (*p != '%' )
        {
            if (!isspace(*p) && *p!=(c=getch()))
            {
                return matchcount;
            }
            else
            {
                continue;
            }

        }

        switch(*++p)
        {
            case 'd':
                ival = va_arg(ap,int*);
                *ival = 0;
                while(isspace(c=getch()))
                {
                    ;
                }
                if(isnumber(c))
                {
                    *ival = c-'0';
                    while(isnumber(c=getch()))
                    {
                        *ival  = *ival*10+(c-'0');
                    }
                    ungetch(c);
                    matchcount++;
                }
                else
                {
                    return matchcount;
                }
                break;
            case 'f':
                fval = va_arg(ap, float*);
                *fval = 0;
                while(isspace(c=getch()))
                {
                    ;
                }
                if(isnumber(c))
                {
                    *fval = c-'0';
                    while(isnumber(c=getch()))
                    {
                        *fval  = *fval*10+(c-'0');
                    }
                    if (c=='.')
                    {
                        int power;
                        for(power=1;isnumber(c=getch());)
                        {
                            power *=10;
                            *fval =  *fval*10 + (c-'0');
                        }
                        ungetch(c);
                        *fval /= power;
                    }
                    else
                    {
                        ungetch(c);
                    }
                    matchcount++;
                }
                else
                {
                    return matchcount;
                }

                break;
            case 'c':
                cval = va_arg(ap, char*);
                *cval = getch();
                break;
           /* case 's':
                for (sval=va_arg(ap,char *);*sval;sval++)
                {
                    putchar(*sval);
                }
                break;
                */
            default:
                break;
        }
    }

    va_end(ap);
    return matchcount;
}
