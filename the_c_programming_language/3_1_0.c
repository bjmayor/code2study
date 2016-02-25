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
    for ( int i=0;i<MAX;i++)
    {
        binsearch(10,test,MAX);
    }

}
int binsearch(int x, int v[], int n)
{
    int low = 0;
    int high = n-1;
    int mid;
    while ( low <= high)
    {
        mid = (low+high)/2; 
        if (x > v[mid])
        {
            low = mid+1;
        }
        else if(x < v[mid])
        {
            high = mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
