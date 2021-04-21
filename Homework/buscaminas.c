#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#define DIM 10
#define MINE -1
#define ERROR_MINE_FOUND 1
#define SPACE ' '
#define ERROR_NONE 3
#define ERROR_SPACE 2
#define ALREDY_COORD 0

    void show (int** m, int dim){
    int i, j;
    for (i=0; i<dim; i++){
            for (j=0; j<dim; j++){
            printf ("\t%d", m [i][j]);//aqui se imprimen los valores

            }
            printf("\n");
    }
            printf("-----------\n");
    }




int main (int argc, char**args){

    int i, j,mineshow,status;
    int** matrix;
    int** another;
    int d, n,x,y,w, mina_counter=0;
    time_t t;
    int  uno,totmine;
    char col;


    mineshow = 0;
    printf("How many mines do you want?\n mines:");
    scanf ("%i", &totmine);

    matrix=(int**)malloc(sizeof(int*)* DIM);//pone la dimension de todo
    another=(int**)malloc(sizeof(int*)*DIM);
    for (i=0; i<DIM; i++){
         matrix[i]=(int*)malloc(sizeof(int)*DIM);
         another[i]=(int*)malloc(sizeof(int)*DIM);//10 bytes
            for (j=0; j<DIM; j++){

            matrix [i][j]= 0;
            another [i][j]= 0;

             }
            }
            printf("Entrando a minas\n");

    while (mina_counter < totmine ){


        x= 0 + rand() / (RAND_MAX / ((DIM - 1) - 1 + 1) + 1);
        y= 0 + rand() / (RAND_MAX / ((DIM - 1) - 1 + 1) + 1);


        //y= rand() % DIM ;
        //printf("%i\n",y);
        if (matrix [x][y]!= MINE){//no repetir
                matrix [x][y]= MINE;
                mina_counter++;
                }

        }
        printf("Entrando a poner numeros 1 2 3\n");
    for (i=0;i<DIM;i++){
        for (j=0;j<DIM;j++){
                        printf("i1=%i\n",i);
                        printf("j1=%i\n",j);
            if (matrix[i][j]==MINE){
               // printf("Encuentra mina\n");
                if (i>0 ){
                    if (matrix [i-1][j]!=MINE){//es para la de arriba de -1
                       // printf("cambia imenos\n");
                        matrix [i-1][j]= matrix [i-1][j] + 1;
                    }
                }
                if (i<DIM){
                    if (matrix [i+1][j]!=MINE){
                        //printf("cambia imas\n");
                        //printf("i=%i\n",i);
                        //printf("j=%i\n",j);
                        matrix [i+1][j]= matrix [i+1][j] + 1;//el de abajo de -1
                        }
                    }
                if (j>0){
                    if (i>0){
                        if (matrix [i-1][j-1]!=MINE)
                            matrix [i-1][j-1]=matrix [i-1][j-1]+1;//el izquierda arriba
                            if  (matrix [i][j-1]!=MINE)
                            matrix [i][j-1]=matrix [i][j-1]+1;//el de atras de -1
                        }
                        if (i<DIM ){
                            if (matrix [i+1][j-1]!=MINE)
                            matrix [i+1][j-1]=matrix [i+1][j-1]+1;
                        }
                    }

                if (j<DIM ){
                    if (i>0){
                        if (matrix [i-1][j+1]!=MINE)
                            matrix [i-1][j+1]=matrix [i-1][j+1]+1;//derecha arriba
                        if (matrix [i][j+1]!=MINE)
                            matrix [i][j+1]=matrix [i][j+1]+1;//derecha -1
                        }
                    if (i<DIM){
                        if (matrix [i+1][j+1]!=MINE)
                            matrix [i+1][j+1]=matrix [i+1][j+1]+1;
                        }
                     }

            }
        }
    }
    printf("entra a while sale de nums\n");

    while (1){
       DisplayTable(matrix,another) ;

     if (mineshow) {
      break;
    }
    int gcol;
    int status;
    int grow;
    printf("Ingresa la fila: ");
    scanf(" %d", &grow);
    printf("Ingresa la columna: ");
    scanf("%d", &gcol);

    status = OpenCell(matrix, another,grow,gcol);
    printf("Salio Opencell %i\n", status);
    if (almostwon(another)) {
      printf("You have won, Congrats!!\n");
      show (matrix, DIM);
      for (i=0; i<DIM; i++){
         free (matrix[i]);
         free (another[i]);
    }
      free (matrix);
      free (another);

    } else if (status == ALREDY_COORD) {
      printf("Ya has abierto esta casilla\n");
    } else if (status == ERROR_MINE_FOUND) {
      printf("Has perdido\n");
       show (matrix, DIM);
      for (i=0; i<DIM; i++){
         free (matrix[i]);
         free (another[i]);
    }
      free (matrix);
      free (another);


    }
  }





    show (matrix, DIM);
    //show(another, DIM);
    for (i=0; i<DIM; i++){
         free (matrix[i]);

         free (another[i]);
    }
    free (matrix);
    free (another);
    return 1;


}
int OpenCell(int** m, int** a,int r, int c){


    //c = toupper(c);
  // Restamos 1 porque usamos la columna como índice
    r--;
  // Convertimos la letra a índice
  int col = c-1;

  //assert(r < DIM && r >= 0);
  //assert(col < DIM && col >= 0);
    if (a[r][col]!=1){
    if (m[r][col] == MINE) {
    return ERROR_MINE_FOUND;
  }
  if (m[r][col] == 0) {
    a[r][col] = 1;
  }else{
  a[r][col] = 1;}
  }
  else
  return ALREDY_COORD;
  }


int almostwon(int**a ) {
  int d;
  for (d = 0; d < DIM; d++) {
    int f;
    for (f = 0; f < DIM; f++) {
      int actual = a[d][f];
      if (actual == 0) {
        return 0;
      }
    }
  }
  return 1;
}
void DisplayTable(int** m, int** a){
    int i,j,r;
    int col;
    printf("Entro Display \n");

    printf("   ");
    for (i = 0; i < DIM; i++) {
     col=i+1;
    printf ("   %i", col);//convierte a letra
    }
    printf("\n");
    r = 1;
    printf(" 1 ");
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            if (m[i][j]!=-1&&a[i][j]==1){//cada que mande ua coord another=1
                if (m[i][j]!=0){

                printf(" %3d", m[i][j]);
                }
                else{
                    printf("    ");
                }
            }
            else{
                printf("   #");
            }
        }
    printf("\n");
    r++;
    if (r<=DIM){
    printf("%2d ", r);
    }
  }
   for (i = 0; i < ((DIM)*4+4); i++) {
  printf("-");
   }
   printf("\n");
}

