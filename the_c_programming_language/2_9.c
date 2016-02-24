#include <stdio.h>
int bitcount(unsigned x);
main()
{
    printf("expexted 3, result is %d\n", bitcount(35)); 
}
int bitcount(unsigned x)
{
    int b=0;
    while (x)
    {
        x&=(x-1);
        b++;
    }
    return b;
}