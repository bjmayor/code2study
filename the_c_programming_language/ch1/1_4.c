#include <stdio.h>
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -20.0;
    upper = 100;
    step = 20;

    fahr = lower;
    printf("华氏温度 摄氏度\n");
    while (celsius <= upper) {
        fahr  = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n",fahr, celsius);
        celsius = celsius + step;
    }
}
