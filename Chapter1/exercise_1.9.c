#include <stdio.h>
#define NOTSPACE '-' //('-') esto es espacio, so nonblank es espacio
 int main (){

{
  int c, lastc;

  lastc = NOTSPACE;

  while((c = getchar()) != EOF) //getchar es la captura del texto "dame el texto"
  {
    if(c == ' ')// si c es igual a blanco (" ") entras a validar el siguiente if
    {
      if(lastc != ' ')
       // printf("1");
        putchar(c);
    }
    else
      putchar(c);// imprime el caracter o la letra
    lastc=c;
  }
     return 0;
}
 }
