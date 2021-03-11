
#include <stdio.h>
#include <ctype.h>

int main (){
 int c, i, sw, sw2,sw3,quotes, underscore;
 sw=0;
 i=0;
 sw2=0;
 sw3=0;
 quotes=0;
 underscore=0;


  while ((c=getchar()) !=EOF){

    if (c== '{')//everytime we have our parenthesis we will put switch on
            sw=1;
    if (c== '(')
            sw=1;
    if (c== '[')
            sw=1;
    if (c== '<')
            sw=1;
    if (c=='"' && sw3==0){//here we use sw3 to limit our value
            sw=1;
            sw3=1;
        }else
            if (c=='"' && sw3==1){//if we find other quotes we will restart sw3 as 1 and sw will go off
            sw=0;
            sw3=1;}//


    if (c=='\''){//everytime we see this quotes the number will be incresing
        sw=1;
        quotes++;}
    if (c=='\`'){//everytime we see this quotes the number will be incresing
        sw=1;
        quotes++;}
    if (c=='_'){
        sw=1;
        underscore++;}



    if (!isdigit(c))//if is not a number
        sw2=0;//sw=0

    if (c==')')//everytime we see the contrapart of our parenthesis sw will restart
        sw=0;
    if (c=='}')
        sw=0;
    if (c==']')
        sw=0;
     if (c=='>')
        sw=0;
    if (c=='\''&& quotes==2){
        sw=0;
        quotes=0;}//we start again with the value of quotes
     if (c=='\`'&& quotes==2){
        sw=0;
        quotes=0;}//we start again with the value of quotes
     if (c=='_'&& underscore==2){
        sw=0;
        underscore=0;}




    if (sw==1)
        putchar (c);// here we will putchar what is inside our parenthesis
    else
        if (isdigit(c)){
            if (sw2==0){
                putchar('X');
                sw2=1;//to only print an x
            }
        }
        else{
            if (c!= '.'){
            if(c!= '!')
            if(c!= '?')
            if(c!= ';')
            if(c!= ':')
            if(c!= ',')
            putchar (c);}

}




}
}
