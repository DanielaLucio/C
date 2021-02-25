#include <stdio.h>

int main (){
    int c;
    char strval[90];
    char val1[4]={"<h1>"};
    char val2[8]={"<strong>"};
    int i, d,  a;
    int sw, sw2,sw3;
    sw = 0;
    sw2 = 0;
    sw3 = 0;
    d=0;

    while ((c = getchar()) != EOF){
        //putchar(sw2);
        if  (c== '<'){
            sw = 1;
            sw2 = 0;
            sw3 = 0;
            d=0;
            for (a = 0; a <= 89; ++a){//helped by Milton Rodriguez to formulated the for
                strval[a] = '\0';//We restart the array to validate next tag
            }
        }

        if (sw == 0){
            if (sw2 == 0 && sw3 == 0){
                putchar(c);
            }
            else {
                if (c == ' ')
                        putchar('_');
                    else
                        putchar(c);
                }

        }
        else{
            strval[d]= c;//storage the character to validated it
            d++;
        }

        if  (c== '>'){
            sw = 0;

            for (i=0;i<4;i++){//Milton Rodriguez helped me to formulated the for
                sw2 = 1;
                if (strval[i]!= val1[i]){
                    sw2 = 0;
                }
            }
             for (i=0;i<8;i++){
                sw3 = 1;
                if (strval[i]!= val2[i]){
                    sw3 = 0;
                }
            }
        }

    }
}
