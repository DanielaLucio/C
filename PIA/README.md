# Project Title: ATM BANK
This will be a program that will make the functions of an ATM BANK using 
the c language 

## Link of youtube video
https://www.youtube.com/watch?v=B52MiyuHglA

### Link of gdb compiler
https://onlinegdb.com/cSRE11w7Z

## ATM FUNCTIONS
This ATM Bank will count with the next functions
- Balance
- Cash withdrawal
- Change of nip
- Cash deposit

### ATM FILES 
Our information will be storage in different files:

**client_info.txt**- As the name says this file will storage the account number, nip and status of our client (the status is if the account is activate or not), an other thing is that from here we will change our nip.

**amount.txt**- This is very important because here we will get our final credit, from here we are going to substract, add and verify all after all the alterations we have made.


*client_info.txt*
```c
1 7718 1
2 8899 0
3 9090 1
```
*amount.txt*
```c
1 100
2 1050
3 1030
```


### ATM SEQUENCE
#### START
1. The program is going to ask for an account number (the account number is unique ), if the account number do not coincides then you will not able to continue.
1. The program will ask for the nip 
1. If the account number and the nip coincides then it will go to the main menu
Note: If the account number and nip do not concides with the client information it will get a message of error.

### Main menu 
A main menu will be display where the atm functions will appear.
```c
 int menu(){
        
          int option;

          printf ("\t--------------------------------------------------------------\n");
          printf ("\t|     *             What do you want to do?         *         |\n"); 
          printf ("\t|                                                             |\n");
          printf ("\t|                                                             |\n");
          printf ("\t| 1 Check balance                  2 Cash withdrawal          |\n");
          printf ("\t|                                                             |\n");
          printf ("\t|                                                             |\n");
          printf ("\t| 3 Change of nip                  4 Cash deposite            |\n");
          printf ("\t|                                                             |\n");
          printf ("\t|                                                             |\n");
          printf ("\t|                      5 exit                                 |\n");
          printf ("\t|                                                             |\n");
          printf ("\t--------------------------------------------------------------\n");
          printf("Type the desired option please:"); 
          scanf ("%i",&option);
          

          return option;

    
    }
```

##### Balance 
What balance is going to show us, is the amount of money that we still have after cash withdrawals and cash deposits.

##### Cash Withdrawal
Cash Withdrawal what is going to do is that first the program will ask us for how many money does we want to withdrawal, after choosing our quantity the program is going to verify if we have the credit to do this withdrawal, if not it will mark error, if yes this amount will be substracted from our amount.txt FILE.

##### Change of nip
When we choose this option the ATM is going to ask us for  a new 4-digit nip and this will be change in the file of client_info.txt.

##### Cash Deposit
Cash Deposit what is going to do is that first will ask us for the amount of money that we want to deposit then the account of who we want to deposite after having chosen our quantity the program is going to verify if we have the credit to do this deposit, if not it will mark error, if yes this amount will be substracted from the person who deposit from our amount.txt file. and, add this quantity to the account of the person was deposited.



### End
