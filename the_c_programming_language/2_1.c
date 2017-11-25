#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
main()
{
    printf("打印标准头的符号常量\n");
    printf("signed char:%d~%d, unsigned char:%d~%d\n",SCHAR_MIN,SCHAR_MAX,0,UCHAR_MAX);
    printf("signed short:%d~%d, unsigned short:%d~%d\n",SHRT_MIN,SHRT_MAX,0,USHRT_MAX);
    printf("signed int:%d~%d, unsigned int:%d~%u\n",INT_MIN,INT_MAX,0,UINT_MAX);
    printf("signed long:%ld~%ld, unsigned long:%d~%lu\n",LONG_MIN,LONG_MAX,0,ULONG_MAX);

    printf("打印计算的范围\n");
    printf("signed char:%f~%f, unsigned char:%d~%f\n",-pow(2,(sizeof(char)*8-1)),pow(2,(sizeof(char)*8-1))-1,0,pow(2,sizeof(char)*8)-1);
    printf("signed short:%f~%f, unsigned short:%d~%f\n",-pow(2,(sizeof(short)*8-1)),pow(2,(sizeof(short)*8-1))-1,0,pow(2,sizeof(short)*8)-1);
    printf("signed int:%f~%f, unsigned int:%d~%f\n",-pow(2,(sizeof(int)*8-1)),pow(2,(sizeof(int)*8-1))-1,0,pow(2,sizeof(int)*8)-1);
    printf("signed long:%f~%Lf, unsigned long:%d~%Lf\n",-pow(2,(sizeof(long)*8-1)),pow(2,(sizeof(long)*8-1))-1.0l,0,pow(2,sizeof(long)*8)-1.0l);

    printf("%d\n", '\0');

}
