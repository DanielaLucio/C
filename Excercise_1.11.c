#include <stdio.h>
#define IN 1
#define OUT 0
 int main ()
 {
     int c, spacecheck;

     spacecheck = OUT;

     while ((c= getchar()) !=EOF){

       if (c== '\n'|| c==' ' || c== '\t'){
        putchar('\n');


     }
        else
            if (spacecheck== OUT){
                putchar(c);


       }


     }
     return 0;
 }


