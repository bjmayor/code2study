#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXBUFFSIZE 100
int np=0;
int buffer[MAXBUFFSIZE];

void push(int number);
int  pop();

int main(int argc, char **argv)
{
    char c;
    int op2;
    while(--argc)
    {
        c = (*++argv)[0];
        printf("deal with %s\n", *argv);
        if (isdigit(c))
        {
            push(atof(*argv));
            continue;
        }
        switch(c)
        {
        case '+':
            push(pop()+pop());
            break;
        case '-':
            op2 = pop();
            push(pop()-op2);
            break;
        case '*':
            push(pop()*pop());
            break;
        case '/':
            op2 = pop();
            if (op2==0)
            {
                printf("error can't divide zero\n");
                return 2;
            }
            else
            {
                push(pop()/op2);
            }
            break;
        default:
            printf("error,unsurported operate\n");
            return 1;
            break;
        }
    }
    printf("the result is %d",pop());
    return 0;
}
void push(int number)
{
    if(np >= MAXBUFFSIZE)
    {
        printf("error , no space left\n");
    }
    else
    {
        buffer[np++] = number;
    }
}
int pop()
{
    if (np<1)
    {
        printf("error, no data in buffer\n");
        return 0;
    }
    else
    {
        return buffer[--np];
    }
}
