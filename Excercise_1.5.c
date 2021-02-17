#include <stdio.h>
 int main (){

    int fahr;

     printf ("Farenheit to Celsius \n");
     printf("\n");

     for ( fahr = 300; fahr >= 0; fahr = fahr-20 )

     printf("%4d %7.2f\n", fahr,  (5.0/9.0)*(fahr - 32));


 return 0
 }
