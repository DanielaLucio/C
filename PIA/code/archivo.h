#include <stdio.h>
#include<stdlib.h>
struct client //in this struct I storage the data of clien.txt
{
  int account [3] ;
  int nip[3] ;
  int status[3] ;
 
} seek;

struct amount//here I storage the data of amount.txt
{
  int account[3];           
  int amount[3];
  
} view;

int menu();
void balance(int acc);
void changepin(int nip, int acc);
void withdrawal(int acc);
void deposit(int acc);
