#include <stdio.h>

#define swap(t,x,y) {t  temp;temp=x,x=y;y=temp;}

main()
{
    int x=5;
    int y=7;
    printf("x=%d,y=%d\n",x,y);
    swap(int,x,y);
    printf("after swap x=%d,y=%d\n",x,y);
}