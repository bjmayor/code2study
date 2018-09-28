#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

void push(double f);
double pop(void);
void printtop(void);
double copytop(void);
void swaptop(void);
void clearstack(void);


int getop(char s[]);

int getch(void);
void ungetch(int c);

main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            push(pop() / op2);
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n",pop());
            break;
        default:
            printf("oerror: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}



void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++]  = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void)
{
    if(sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("erorr, stack empty\n");
        return 0.0;
    }
}
void printtop(void)
{
    if(sp > 0)
    {
        printf("the top is %f\n", val[sp-1]);
    }
    else
    {
        printf("erorr, stack empty\n");
    }
}
double copytop(void)
{
    if(sp > 0)
    {
        return val[sp-1];
    }
    else
    {
        printf("erorr, stack empty\n");
        return 0.0;
    }

}
void swaptop(void)
{
    if(sp > 1)
    {
        double top = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = top;
    }
    else
    {
        printf("not enough data\n");
    }
}
void clearstack(void)
{
    sp = 0;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

int getop(char s[])
{
    int i,c;
    while ((s[0] = c = getch()) == ' ' || c=='\t')
        ;

    s[1] = '\0';
    if (!isdigit(c) && c!='.' && c!='-')
    {
        return c;
    }
    i=0;
    if (isdigit(c) || c=='-')
    {
        while(isdigit(s[++i] = c = getch()));
    }

    if (c == '.')
    {
        while(isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c == '-')
    {
        return c;
    }
    if (c!=EOF)
        ungetch(c);

    return NUMBER;
}
