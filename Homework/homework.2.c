
#include<stdio.h>
#define K 10 /* number of primes*/

void binary(int n);
main() {

int sw, i, j;
  int n = 1;
  int checker = 1;
  int p;
  char b[8]={0};//start at zero
  while(checker <= K){// checker do not pass our constant
    p = 0;
    for(i=1; i<= n; i++){
        if(n%i==0){
        p++;

        }
      }



    if(p==2||n==1){ //if p=2 means that our number only is divisible 2 times
        binary(n);//storage in binary /*helped by Milton Rodriguez to formulate the storage*/
      checker++;
    }

    n++; //following number
}
  }


void binary(int n)
{
    int i=0;
    int base[10]={0}; //Start at 0

    while(n>0) //n is always bigger than 0
    {

        base[i]= n%2;// residuo storage on i
        n/=2; // division
        ++i; // increase the position
    }


    for(int x=8;x>=0;--x)   // Locate 0
    {
       printf("%d",base[x]);
    }
     printf("\n");

}
