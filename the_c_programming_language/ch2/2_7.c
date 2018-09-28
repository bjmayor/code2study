#include <stdio.h>
unsigned int invert(unsigned int x, int p, int n);
main()
{
    printf("test result is %d\n",invert(42,3,2));
}
unsigned int invert(unsigned int x, int p, int n)
{
    //return (~(x>>n | ~0<<n)<<n) | (~(~(~0<<n)<<n) & x);
    return (~(~0<<n)<<p+1-n) & ~0 ^ x;
}
