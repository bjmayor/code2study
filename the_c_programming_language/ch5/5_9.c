#include <stdio.h>
static char  daytab[2][13] = {
    {0,31,28,31,30,31,30,31,30,31,30,31,30},
    {0,31,29,31,30,31,30,31,30,31,30,31,30}
};

int day_of_year(int year, int month, int day)
{
    int i,leap;
    char (*temp)[13] = daytab;
    leap = year%4 == 0 && year%100!=0 || year%400==0;
    for (i=1; i< month;i++)
    {
        day += (*(temp+leap))[i];
    }
    return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i,leap; 
    char (*temp)[13] = daytab;
    leap = year%4 == 0 && year%100!=0 || year%400==0;
    for (i=1; yearday > (*(temp+leap))[i];i++)
    {
        printf("i=%d,yearday=%d\n",i,yearday);
        yearday -= (*(temp+leap))[i];
    }
    *pmonth = i;
    *pday = yearday;
}

main()
{
    int m,d;
    month_day(1988,60,&m,&d);
    printf("expected is 2, 29, result is %d,%d\n",m,d);
}
