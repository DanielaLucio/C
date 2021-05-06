//references and collaborations from: Dr.Satu Elisa, Raul Chavez & Abner

#include "archivo.h"

int main() {
  int cycle=0;
  int k, i = 0;
  char actual, nombre;
  char trabajador[Work + 1];
  int option;
  while (cycle==0){
  printf ("--------------------------------------------------------------\n");
  printf ("| Hello welcome to assistance program what do you want to do? |\n");
  printf ("| 1 Add new worker                                            |\n");
  printf ("| 2 register attendance                                       |\n");
  printf ("| 3 register exit                                             |\n");
  printf ("| 4 exit program                                              |\n");
  printf ("--------------------------------------------------------------\n");
  scanf ("%d",&option);
  
    if (option==1){
      pin_registration();
     }
    if (option==2){
      attendance_list('i');
       
    }
   
    if (option==3){
      attendance_list('o');
       
    }
    
     if (option==4){
         cycle=1;
    }
    
    /* if (option==5){
     reports();
       
    */
  }
       
    
    return 0;  
 }
  
   void pin_registration(){//take data of new workers
       
       FILE* entrada = fopen("trabajadores.txt", "r");
       char* name;
       int mon,tues,wend,thur,fri,sat,sun;
       char* enter;
       char* exits;
       char namear [20];
       int PIN [MAX];
       int i=1;
       int pin_count=0;
       printf ("add your name:");
       scanf("%s",&name);
       printf ("capture your working days \n");
       printf("Mon, 1=si 0 = No: "); 
       scanf("%i",&mon);
       printf("tuesday, 1=si 0 = No:  ");
        scanf("%i",&tues);
       printf("Wends, 1=si 0 = No:  ");
       scanf("%i",&wend);
       printf("thursday, 1=si 0 = No: ");
       scanf("%i",&thur);
       printf("Friday, 1=si 0 = No: ");
       scanf("%i",&fri);
       printf("saturday, 1=si 0 = No:  ");
       scanf("%i",&sat);
       printf("Sunday, 1=si 0 = No: ");
       scanf("%i",&sun);
      
       printf("add your enter hour\n ");
       printf("Write is as 'X:XX:XX': ");
       scanf("%s",&enter);
       printf ("add your exit hours\n ");
       printf("Write is as 'X:XX:XX': ");
       scanf("%s",&exits);

       while (feof(entrada)==0) { 
        if ((fgetc(entrada))=='\n') { 
        pin_count++;

        }
      } 
    pin_count++;
    printf("your pin is: %d \n", pin_count);
    printf("This info have been storage in trabajadores file\n");

    fclose(entrada);
    FILE* escritura = fopen("trabajadores.txt", "a");//a will print and not erase the info
       
    fprintf(escritura,"%i- %s- %i %i %i %i %i %i %i- %s %s  \n",pin_count++, &name, mon, tues, wend, thur, fri, sat, sun,&enter, &exits);
      fclose(escritura);
   }
  
    void attendance_list(int t){
    int pin2,pinadd; 
    int pin_count=0;

    
  
    printf ("Enter your PIN: ");
    scanf("%i", &pinadd);
 
    FILE* checa_pin = fopen("trabajadores.txt", "r");
    while (feof(checa_pin)==0) { 
        if ((fgetc(checa_pin))=='\n') { 
            pin_count++;
        
        }
    }
    fclose(checa_pin);

    if (pinadd<=pin_count){//check if pin exists
            timecome(pinadd, t);
    }else 
    printf("This pin does not exist sorry bro:(\n");

    

    }
    
    void timecome(int pin, char t){//of t=i is entrance if t=o is exit
    time_t timeac;
    time(&timeac);
    struct tm *timer = localtime(&timeac);
    int sega=timer->tm_sec;
    int mina=timer->tm_min;
    int houra=timer->tm_hour;
    int yeara=timer->tm_year+1900;
    int montha=timer->tm_mon+1;
    int daya=timer->tm_mday;
    int wdaya=timer->tm_wday;
    int inttime;
    char dia [7]= "Jueves";
    FILE* captor = fopen("attendance.txt", "a");
    fprintf(captor, "%c%d %lu %d %d/%d/%d %d:%d:%d\n",t, pin, (unsigned long)time(NULL),wdaya,  daya, montha, yeara,houra, mina, sega);
    fclose(captor);
    if (t=='i'){//i means entry
     printf("welcome your entry have been register\n");}
     
    if (t=='o'){//o output
       
        printf("Goodbye your exit have been compleate\n") ;
        
            
        
        inttime = difftimes(pin);
        FILE *reporte=fopen("reporte.txt","a");
        
        fprintf(reporte,"El trabajador con PIN %d trabajo %i segundos el dia %s\n",pin,inttime,dia);
    }
    
  
}
int difftimes(int pin) {
        char time1[20];
        int onet, twot;
        int diftimer;
        int c;
        FILE *diff = fopen("attendance.txt", "r");
        while ((c = fgetc(diff)) != EOF)
        {
            if (c == 'i')
            {
                c = fgetc(diff) - '0';
                if (c == pin)
                {
                    c = fgetc(diff) - '0';
                    fgets(time1, 11, diff);
                    onet = atoi(time1);
                   
                }
            }
        }
    diftimer = (unsigned long)time(NULL) - onet;
    fflush(diff);
    fclose(diff);
    return diftimer;
}
/*
   void reports(){
    char aux;
    char temp [50];
    int cont=0;
    int i, j;
    int sec, min, hora,year, dia, wdia, pin, ent_ex, mes;
    char fecreg[8];
    char horareg[8];
    int day_get;
    int month_get;
    int year_get;
      time_t timeac;
      time(&timeac);
         struct tm *timer = localtime(&timeac);
        int actualsec=timer->tm_sec;
        int actualmin=timer->tm_min;
        int actualhora=timer->tm_hour;
        int actualyear=timer->tm_year+1900;
        int actalmes=timer->tm_mon+1;
        int actualdia=timer->tm_mday;
        int actualwdia=timer->tm_wday;
      
     FILE* at=fopen("attendance.txt","r"); 
     if (at==NULL){
         printf("No se pudo abrir F :(");
         exit(1);
        
     }
     while(!feof(at)){
         fgets(temp,50,at);
         cont++;
     }
     rewind(at);

     
     trab=(workers*)malloc(cont*sizeof(workers));
     if (trab==NULL){
         printf("Sth went wrong in memory sorry boy :(");
         exit(1);
     }
     for (i=0;i<=cont;i++);{
         printf("entro for\n");
         empty();
         printf("sale empty\n");
         aux='0';
         for (j=0;aux!=' ';j++){
             printf("entro for de j \n");
             aux= fgetc(at);
             if (aux!=' '){
                 temp[j]= aux;
             }
         }
         copy(temp,i);
         printf("salio de copy\n");
          fgets(temp,2,at);
          trab[i].pin=atoi(temp);
         fgets(temp,3,at);
         trab[i].entrada_salida=atoi(temp);
         fgets(temp,4,at);
         
         trab[i].mes =atoi(temp);
         
         printf("sale de fgets\n");
         printf("pin %s %d %d %d \n",trab[i].fecha,trab[i].pin,trab[i].entrada_salida,trab[i].mes);
     }
      
          
}

void empty(char temp[50]){
   
    int i;
  
        
        temp ='\0';
        printf("entro for de empty\n");
    
}
void copy (char temp[], int i){
    printf("entro copy\n");
    int n=strlen(temp)+1;
    trab [i].fecha=(char*)malloc (n *sizeof(char));
    if (trab[i].fecha==NULL){
        printf("No se pudo reservar memoria :(\n");
        exit(1);
    }
   
    strcpy(trab[i].fecha,temp);
    
}*/
//references and collaborations from: Dr.Satu Elisa, Raul Chavez & Abner
