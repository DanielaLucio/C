#include <stdio.h>
#define NONBLANK '-' //('-') esto es espacio, so nonblank es espacio
 int main (){

{
  int c, lastc;

  lastc = NONBLANK;

  while((c = getchar()) != EOF) //getchar es la captura del texto "dame el texto"
  {
    if(c == ' ')// si c es igual a blanco (" ") entras a validar el siguiente if
    {
      if(lastc != ' ')// last c es diferente a espacio, si hubiera dos espacios lo notaria
       // printf("1");
        putchar(c);
    }
    else
        //printf("2");
      putchar(c);// imprime el caracter o la letra
    lastc=c;
  }
     printf(lastc);
     return 0;
}
 }
