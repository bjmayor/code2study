#include <stdio.h>
#include <ctype.h>
#include <math.h>
double atof(char s[]);
main()
{
    char t1[] = "+32";
    char t2[] = "32";
    char t3[] = "-32";
    char t4[] = "-32.240";
    char t5[] = "-.5";
    char t6[] = "+321.6";
    char t7[] = "+.4447";
    char t8[] = "+.4447E9";
    char t9[] = "+4447000000E-9";
    char t10[] = "+.4447e+9";
    printf("source is %s, expected is 32.000000, result is %f\n",t1,atof(t1));
    printf("source is %s, expected is 32.000000, result is %f\n",t2,atof(t2));
    printf("source is %s, expected is -32.000000, result is %f\n",t3,atof(t3));
    printf("source is %s, expected is -32.240000, result is %f\n",t4,atof(t4));
    printf("source is %s, expected is -0.500000, result is %f\n",t5,atof(t5));
    printf("source is %s, expected is 321.600000, result is %f\n",t6,atof(t6));
    printf("source is %s, expected is 0.444700, result is %f\n",t7,atof(t7));
    printf("source is %s, expected is 444700000.000000, result is %f\n",t8,atof(t8));
    printf("source is %s, expected is 4.447000, result is %f\n",t9,atof(t9));
    printf("source is %s, expected is 444700000.000000, result is %f\n",t10,atof(t10));
}
double atof(char s[])
{
    double val, power;
    int i,sign,index=1,indexSign;

    for (i=0;isspace(s[i]);i++)
        ;
    sign = (s[i]=='-')?-1:1;
    if(s[i]=='-' || s[i]=='+')
        i++;
    for (val=0.0;isdigit(s[i]);i++)
    {
        val = 10.0*val + (s[i]-'0');
    }
    if (s[i]== '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]);i++)
    {
        val = 10.0*val + (s[i]-'0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i]=='E')
    {
        i++;
    }

    indexSign = (s[i]=='-')?-1:1;
    if(s[i]=='-' || s[i]=='+')
        i++;
    for (index=0;isdigit(s[i]);i++)
    {
        index  = index*10 + (s[i]-'0');
    }


    return sign * val/power * pow(10,index*indexSign);
}
