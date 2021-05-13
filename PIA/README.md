# Project Title: ATM BANK
This will be a program that will make the functions of an ATM BANK using 
the c language 
##ATM FUNCTIONS
This ATM Bank will count with the next functions
- Balance
- Cash withdrawal
- Change of nip
- Cash deposite

###ATM FILES 
Our information will be storage in different files.  The first file will be:

**client_info.txt**- As the name says this file will storage the account number, nip and status of our client (the status is if the account is activate or not), an other thing is that from here we will change our nip.
**amount.txt**- This is very important because here we will get our final credit, from here we are going to substract, add and verify our actual credit after all the alterations we have made.
**cashier_suply.txt**- This is going to tell us the amount of money that the atm bank has to provide. Every time we make a cash withdrawal the amount of this will be substracted from the amount storage in this file.

###ATM SEQUENCE
####START
1. The program is going to ask for an account number (the account number is unique ), if the account number do not coincides then you will not able to continue.
1. The program will ask for the nip 
1. If the account number and the nip coincides then it will go to the main menu
Note: If the account number and nip do not concides with the client information it will get a message of error, if this error repeats more than 2 times the account will be desactivate.

### Main menu 
A main menu will be display where the atm functions will appear.
```c
#include <stdio.h>
int main(){
  int cycle=0; 
  int option;
  while (cycle==0){
  printf ("--------------------------------------------------------------\n");
  printf ("|     *             What do you want to do?         *                    |\n\n"); 
  printf ("| 1 Check balance                  2 Cash withdrawal                |\n");
  printf ("| 3 Change of nip                  4 Cash deposite                    |\n");
  printf ("|                             5 exit                                                     |\n");
  printf ("--------------------------------------------------------------\n");
  scanf ("%d",&option);


  }
    return 0;  
 }
```
Code Blocks (View):


     -------------------------------------------------------------- 
     |     *             What do you want to do?         *                   |
	 
	 | 1 Check balance                  2 Cash withdrawal                |
     | 3 Change of nip                  4 Cash deposite                    |
	 |                             5 exit                                                     |
	 -------------------------------------------------------------- 
##### Balance 
What balance is going to show us the amount of money that we still have after cash withdrawals and cash deposites.
##### Cash Withdrawal
Cash Withdrawal what is going to do is that first will give us some options about how much money we want to withdrawal, after choose our quantity the program is going to verify if we have the credit to do this withdrawl, if not it will mark error if yes, this amount will be substracted from our amount.txt file.
#####Change of nip
When we chose this option the atm is going to ask us for a re-confirmation of account number and nip, this to verify that the owner is doing this, if this coincide the atm will ask you to compute a new 4-digit nip and this will be change in the file of client_info.txt
#####Cash Deposite
Cash Deposite what is going to do is that first will ask us to the account of who we want to deposite then this will give us some options about how much money we want to deposite after choose our quantity the program is going to verify if we have the credit to do this deposite, if not it will mark error if yes, this amount will be substracted from our amount.txt file. and add this quantity to the account of the person we deposited.

###Sequence Diagram
                    
```seq
Andrew->China: Says Hello 
Note right of China: China thinks\nabout it 
China-->Andrew: How are you? 
Andrew->>China: I am good thanks!
```

###End
