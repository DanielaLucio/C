#include <stdio.h>
 int main (){

    int fahr;

     printf ("Farenheit to Celsius \n");
     printf("\n");
     printf("   F \t  C");
     printf("\n");

     for ( fahr = 300; fahr >= 0; fahr = fahr-20 )

     printf("%4dF %7.2fC\n", fahr,  (5.0/9.0)*(fahr - 32));


 return 0;
 }
