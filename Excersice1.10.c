#include <stdio.h>


int main (){

  int c;

    while((c = getchar()) != EOF)
  {
      if (c== '\t')
       {
        putchar ('\\');
        putchar ('t');
       }

        if (c== '\b')
        {
            putchar('\\');
            putchar ('b') ;
        }



        if (c== '\\')
        {
           putchar ('\\');
           putchar ('\\') ;
        }


            if (c !='\b'&& c != '\\' && c !='\t')
            {
                 putchar (c);
            {

            }


            }


  }

return 0;

}
