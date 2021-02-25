#include <stdio.h>
/* print Celsius-Fahrenheit table*/
int main(){

float celsius, fahr;
float lower, upper ,space;

lower= -30;
upper=100;
space= 20;

celsius=lower;
while (celsius<=upper){
    fahr= ((9*celsius)/5) + 32;

    printf ("%.2fC\t %.2f F \n", celsius, fahr);
    celsius= celsius + space;
}
 return 0;

}
