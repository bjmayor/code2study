#include <stdio.h>
main(){
    int c;
    c = getchar()!=EOF;
    if(c==1)
    {
        putchar('1');
    }
    else
    {
        putchar('0');
    }
}
