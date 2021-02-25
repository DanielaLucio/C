#include<stdio.h>

int main()
{
    printf("A program print Fahrenheit-Celsius\n");

    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;


        printf("Fahr\tCelsius\t \n");

    while(fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr - 32.0);
            printf("%.2f \t %.2f\n", fahr, celsius);
            fahr = fahr + step;
    }

    return 0;
}
