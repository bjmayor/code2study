#include <stdio.h>
#define MAX 1000000
int binsearch(int x, int v[], int n);
main()
{
    int test[MAX];
    for ( int i=0;i<MAX;i++)
    {
        test[i] = i*10;
    }
    for (int i=0;i<MAX;i++)
    {
        binsearch(10,test,MAX);
    }
}
int binsearch(int x, int v[], int n)
{
    int low = 0;
    int high = n-1;
    int mid= -1;
    while ( low < high-1)
    {
        mid = (low+high)/2; 
        if (x >= v[mid])
        {
            low = mid;
        }
        else
        {
            high = mid-1;
        }
    }

    if (v[low] == x)
    {
        return low;
    }
    else if(v[low+1] ==x)
    {
        return low+1;
    }
    else if(v[high] == x)
    {
        return high;
    }

    return -1;
}
