#include <stdio.h>
unsigned int rightrot(unsigned int x ,int n);
main()
{
    printf("expected 20, result is %d\n",rightrot(18, 2));
}
unsigned int rightrot(unsigned int x ,int n)
{
    /*
    int number = 0;
    int temp = x;
    while(temp>0)
    {
        temp = temp>>1;
        number++;
    }
    return ((~(~0<<number)) &  x<<(number-n)) | x>>n;
    */
    return ~(~0<<n)&x << 32-n  | x>>n;
}
