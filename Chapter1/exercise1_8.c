#include <stdio.h>
 int main (){
//Tabs counter
     int  ns,nt, nb, nl;
     char c;
     ns = 0;
     nt=0;
     nb=0;
     nl=0;

     while ((c=getchar())!=EOF){
        if (c== ' ')
            ns++;
        if (c=='\t')
            nt++;
        if (c== '\b')
            nb++;
        if (c== '\n')
            nl++;}

    printf ("\nYour number of spaces are: %i", ns);
    printf ("\nYour number of tabs are: %i", nt);
    printf ("\nYour number of backspaces are: %i", nb);
    printf ("\nYour number of new line are: %i", nl);


     return 0;
 }
