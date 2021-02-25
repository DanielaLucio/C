#include <stdio.h>
/* this program is going to read an HTML text and convert it to plain text also
replace spaces  to underscore in header and bold faced text*/

int main (){
    int c;
    char strval[90];//array to validate the current tag
    char val1[4]={"<h1>"};//tags to validate
    char val2[8]={"<strong>"};//tags to validate
    int i, d,  a;// these are the variables of the cycles
    int sw, sw2,sw3;//these are to turn on or off the conditions, sw is for putchar or not putchar, sw2 is for replace  or no replace tag 1 and sw3 same as sw2 but for tag 2
    //switches start
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

        if (sw == 0){//here enters when its not a tag
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
        else{//here storage the current tag
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
                if (strval[i]!= val2[i]){//is going to validate each character to check if are not the tag
                    sw3 = 0;
                }
            }
        }

    }
}
