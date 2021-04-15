#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"
#define MAXOP 100 /* max size*/

int sw1,sw2,sw3,swnum,swquestion,swnum,position;
    char avalname[27];
    char valname,yesno,valnameq;
    double valnum,avalnum[27];
    int numval = 0;
    char cr;
    int more= 0;
    char var[27];

main()
{
    int type,j,v;
    double op2;
    char s[MAXOP];// array of 100

    sw1=0;
    sw2=0;
    sw3=0;
    swnum=0;

    while ((type = getop(s)) != EOF) {

        switch (type) {
            case NUMBER:

            if (sw1 == 1){//if there is a letter
                if (sw2 == 0 && sw3 == 0){
                    push(atof(s));
                    push (valnum);
                }else//if there is a : or =
                    valnum = atof(s);
            }else{
                push(atof(s));
            }
            break;
            case '+':
            push(pop() + pop());
            break;

            case '*':
            push(pop() * pop());
            break;

            case '-':
                ;
            op2 = pop();
            push(pop() - op2);
            break;
            case '/':

            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;

            case '\n':
            if (swquestion == 1&&yesno == 'y'){

                SaveVar();// if we answer y we save the variable
                sw1=0;/*restart*/
                sw2=0;
                sw3=0;
                swquestion = 0;
                position = 0;
                yesno = '/0';
            }
            if (sw1==1){
                if (sw2==1){
                    if (sw3 == 1);{
                        SaveVar();
                        sw1=0;
                        sw2=0;
                        sw3=0;
                    }
                }else if (sw3 == 1){

                    SaveVar();
                    sw1=0;
                    sw2=0;
                    sw3=0;
                    }
                }



            if (swnum > 0)
                printf("\t%.8g\n", pop());//gives the result
            swnum = 0;
            break;
            default:
                if (cr >= 'A' && cr <='Z'){
                    cr = cr - 'A' + 'a';
                }
                if (cr >= 'a' && cr <='z'){
                    if (swquestion==1)
                        yesno = cr;//we convert to character yesno
                    else{

                        if (sw1 == 1){//when we have multiple variables
                            SumVar(cr);
                            SumVar(valname);
                        sw1 = 0;
                        }
                        if (swnum == 1){//variable and number
                            SumVar(cr);//
                            swnum = 0;
                        }
                        sw1 = 1;
                        valname = cr;
                    }
                }
                if (cr == ':' && sw1 == 1)
                        sw2=1;
                if (cr == '=' && sw1 == 1)
                        sw3=1;
                if (sw1 == 0 && swquestion==0)
                    printf("error: unknown command %s\n", s);
            break;
        }
    }

}
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{

    if(sp < MAXVAL){

            val[sp++]=f;
            swnum = 1;

        }
    else
        printf("error:stack full, cant push %g\n",f);
}

double pop(void)
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;// devuelve el 0
    }
}

#include<ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i,c;




    i = 0;


    while((s[0] = c = getch()) == ' ' || c =='\t')//gets the spaces

        ;
    s[1] = '\0';

    i = 0;
    if(!isdigit(c) && c!='.' && c!='-'){
        cr = c;
        return c;
    }
    if(c=='-')
        if(isdigit(c=getch()) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }

    if(isdigit(c))
        while(isdigit(s[++i] =c =getch()))
            ;

    if(c=='.')
        while(isdigit(s[++i] = c=getch()))
            ;

    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void SaveVar()
{
     int j,swsave;
    if (swquestion == 1){
        avalnum[position] = valnum;
        printf ("asignation done \n");


    }else{
            if (sw2== 1){

                if (sw3==1){

                    if (numval==0){
                            avalname[0]= valname;
                            avalnum[0] = valnum;
                            numval++;
                            sw1=0;
                            sw2=0;
                            sw3=0;
                            printf ("asignation done  \n");
                    }else{
                        swsave = 0;
                        for (j=0;j<numval;j++){
                            if (avalname[j] == valname){

                                    avalname[j]= valname;
                                    avalnum[j] = valnum;
                                    swsave = 1;

                                    sw1=0;
                                    sw2=0;
                                    sw3=0;
                                    printf ("asignation done \n");

                            }
                        }
                        if (swsave==0){

                            avalname[numval]=valname;
                            avalnum[numval]=valnum;
                            numval++;
                            sw1=0;
                            sw2=0;
                            sw3=0;
                            printf("asignation done \n");
                        }
                    }
                }
            }else if (sw3 == 1){
                    if (numval==0){
                            avalname[0]= valname;
                            avalnum[0] = valnum;
                            numval++;
                            sw1=0;
                            sw2=0;
                            sw3=0;
                            printf ("asignation done \n");//var with =
                    }else{
                        swsave=0;
                        for (j=0;j<numval;j++){
                            if (avalname[j] == valname){
                                swquestion = 1;
                                position = j;
                                valnameq = valname;
                                swsave=1;
                                printf("are you sure? Y yes, N no \n ");


                                }
                            }
                            if (swsave==0){
                                avalname[numval]=valname;
                                avalnum[numval]=valnum;
                                numval++;
                                sw1=0;
                                sw2=0;
                                sw3=0;
                                printf("asignation done  \n");// more than 1 variable in :
                            }
                        }

                    }
                }

                    sw1=0;
                    sw2=0;
                    sw3=0;



}




void SumVar(char var1)
{
    int swval,j;

    swval = 0;
    for (j=0 ;j<numval;j++){

        if(var1==avalname[j])
            {

            val[sp++]= avalnum[j];
            swval=1;
            }

        }
        if (swval == 0)// if we do not find the letter we put 0
            val[sp++]= 0;
}

    /*references from The C programming Language Kernighan*/
