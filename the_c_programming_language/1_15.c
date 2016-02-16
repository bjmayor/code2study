#include <stdio.h>
float cacutelateCelsius(int fahr);
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("华氏温度 摄氏度\n");
    while (fahr <= upper) {
        celsius = cacutelateCelsius(fahr); 
        printf("%3.0f %6.1f\n",fahr, celsius);
        fahr = fahr + step;
    }
}

float cacutelateCelsius(int fahr)
{
   return  (5.0/9.0) * (fahr-32.0);
}