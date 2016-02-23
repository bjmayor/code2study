#include <stdio.h>
int setbits(unsigned int x,int p,int n,unsigned int y);
main()
{
    printf("result is %d\n", setbits(51,3,2,3));
}
int setbits(unsigned int x,int p,int n,unsigned int y)
{
    return (y & ~(~0<<n))<<(p-n+1) | (x& ~((~(~0<<n))<<(p-n+1)));
}