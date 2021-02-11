#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */
int main()
{
float fahr, celsius;
float lower, upper, distance;
lower = 0; /* lower limit of temperature scale */
upper = 300; /* upper limit */
distance = 20; /* step size means that it will be incrementing 20 by 20*/
fahr = lower;//fahr is equal to a 0
while (fahr <= upper) {// while Fahr be less equal as 300 , Celsius will be this
celsius = (5.0/9.0) * (fahr-32);
printf("%.2f F \t%.2f C\n", fahr, celsius);
fahr = fahr + distance;
}
return 0;
}
