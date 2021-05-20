#include <stdio.h>
#include "archivo.h"


 

int main ()
{
  int action=0;
  int sw=0;
  int swacc=0;
  int count= 0;//count tells us how many registers we have
  int acc, pin;
  int i,j;
  int decision;
   i=0;
   j=0;
  FILE *conf = fopen ("clien.txt", "r");
  if (conf == NULL){
      printf ("no se pudo leer\n");
      exit (1);
  }
  while (action!= 5){//if action is 5 program will finish
      sw=0; swacc==0;
      printf ("                   Hello welcome to the D&R ATM Bank  \n\n ");
      printf ("Please enter your account number:   ");
      scanf("%d",&acc);//account storage
      while (!feof (conf)!=' '&&count<3&&sw==0){
        fscanf(conf,"%d %d %d",&seek.account[i], &seek.nip[i], &seek.status[i]);//with our struct we storage the file regiters
        if(seek.account[i]==acc){
            sw=1; 
            swacc=1;
            printf("ingresa nip:");
            scanf("%d", &pin);
            if (pin==seek.nip[i]){//if our nip and account match
                if (seek.status[i]==1){
                    printf("\nWelcome\n");
                    action=menu(); //we display the menu
                     if (action==1){
                         balance(acc);
                     }
                     if (action==2){
                        withdrawal(acc);
                     }
                     if (action==3){
                        changepin(pin, acc);
                     }
                     if (action==4){
                         deposite(acc);
                     }
                     if (action==5){
                         printf("Bye have a nice day\n");
                     }
           
                }else{
                     printf(" Your account is blocked please consult your bank\n");
                }
     
             }else{
                 printf("Your NIP is incorrect\n");
                 printf("if you continue having problems please consult the bank\n");
             }
         }
        count++;
        i++;
     
        }
         if (swacc==0){
            printf("Your account does not exit, try again\n");
     
      
   
  } 
   rewind(conf);//to start since the beginig the file after we alredy complete an action
    count=0;
    }
    
      fclose (conf);
}

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
    
    void balance(int acc){//in balance we are only going to read the file 
        int i=0;
        int count=0;
        FILE*balance= fopen("amount.txt", "r");
        while (!feof (balance)!=' '&&count<=2)//count is the number of registers
        {  
            fscanf(balance,"%d %d ",&view.account[i], &view.amount[i]);
            if(view.account[i]==acc){
                  printf("The balance of %d is %d \n\n", view.account[i], view.amount[i]);
             }
            
           
            i++;
            count++;
        } 
    
    fclose(balance);
    }
        

    void changepin(int nip, int acc){
        int pin;
        int count=0;
        int i,j;
        i=0;
        j=0;
        FILE* analyze=fopen("clien.txt","r");
        printf("Enter your 4 digit new nip:");
        scanf("%d",&pin);
        while (!feof (analyze)!=' '&&count<=2)
        { 
            fscanf(analyze,"%d %d %d",&seek.account[i], &seek.nip[i], &seek.status[i]);
            if(seek.nip[i]==nip&&seek.account[i]==acc){//if these match then seek.nip will be equal to the new nip
                seek.nip[i]=pin; 
                printf("The account number %i your new NIP is :%d \n\n", seek.account[i], seek.nip[i]);
            }
            
            i++;
            count++;
        } 
        fclose(analyze);
        
        FILE* recite = fopen("clien.txt", "w");
        for(j=0; j<i;j++){//j is going to initialized i
        fprintf(recite,"%d %d %d \n", seek.account[j], seek.nip[j], seek.status[j]);
        }
        fclose(recite);
    }
       
    
    void withdrawal(int acc){
        int amount;
        int count=0;
        int sw=0;
        int i,j;
        i=0;
        j=0;
       
          FILE* read = fopen("amount.txt","r" ) ;
          printf("How many money do you want to withdrawal?\n");
          scanf("%d", &amount);
          while (!feof (read)!=' '&&count<=2){
            fscanf(read,"%d %d ",&view.account[i], &view.amount[i]);
            if(view.account[i]==acc){
                view.amount[i]= view.amount[i]-amount;
                
                printf("%d you have withdrawal %d \n\n", view.account[i], amount);
            }
            
            
            i++;
            count++;
        }  
        fclose(read);
        FILE* caught = fopen("amount.txt","w");
        for(j=0; j<i;j++){//initialize i
       
        fprintf(caught,"%d %d \n", view.account[j], view.amount[j]);
        
        }
        fclose(caught);
    }
        
    void deposite(int acc){
        int count=0;
        int i,j, d;
        i=0;
        j=0;
        d=0;
        int amount;
        int accgive;
        
        FILE* dep = fopen("amount.txt","r" ) ;
        printf("How many money do you want to deposite?\n\n");
        scanf("%d", &amount);
        printf("To which account?:");
        scanf("%d", &accgive);
         while (!feof (dep)!=' '&&count<=2){
            fscanf(dep,"%d %d ",&view.account[i], &view.amount[i]);
            if(view.account[i]==acc){
                view.amount[i]= view.amount[i]-amount;//the account who deposites is going to lose that amount
            }
            if (view.account[d]==accgive){
                view.amount[d]= view.amount[d]+amount;//to the account to which it was deposited that amount is going to be add
            }
            i++;
            d++;
            count++;
           
         }
        fclose(dep);
        FILE* operation = fopen("amount.txt", "w");
        for(j=0; j<i&&j<d;j++){
        fprintf(operation,"%d %d \n", view.account[j], view.amount[j]);
        }
        printf("Your deposite has been done\n\n");
        fclose(operation);
    }
