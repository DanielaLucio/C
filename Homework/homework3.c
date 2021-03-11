#include <stdio.h>

int main (){
 int c, i, sw;
 sw=0;

  while ((c=getchar()) !=EOF){

    switch (c){
    case '0': case '1': case '2': case '3': case '4': case '5':
    case '6': case '7': case '8': case '9':
        sw=1;
         if (sw==1)
            printf("x");}

    switch (c){
    case '{': case '}':
        sw=0;
        if (sw==0)
        putchar (c);
        break;



    case '.':
        sw=1;
        if (sw==1)
        putchar ('\0');
        break;

    default:
        sw=0;
    if (sw==0){
        putchar (c);
    }
    }
  }
}


