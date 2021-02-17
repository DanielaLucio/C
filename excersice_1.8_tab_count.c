#include <stdio.h>
 int main (){
//Tabs counter
     int c, n1;
     n1 = 0;

     while ((c=getchar())!=EOF)
        if (c== '\t')
        n1++;
     printf ("\nYour number of spaces are: %d", n1);


     return 0;
 }
