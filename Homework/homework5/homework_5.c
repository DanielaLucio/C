/*Como compilar en codigo? 
1-Si usas el gdb compiler (opcion más viable) ingresa este codigo que es el main.c, despues de eso puedes ingresar cualquiera de los otros 
de cualquier manera con su reespectivo nombre
Primero te pedira el numero de minas el cual puede ser menor a 80*/

#include <stdio.h>
#include<stdlib.h>
#include "calc.h"
#define DIM 10
#define MINE -1
#define ERROR_MINE_FOUND 1
#define SPACE ' '
#define ERROR_NONE 3
#define ERROR_SPACE 2
#define ALREDY_COORD 0





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

    matrix=(int**)malloc(sizeof(int*)* DIM);
    another=(int**)malloc(sizeof(int*)*DIM);
    for (i=0; i<DIM; i++){
         matrix[i]=(int*)malloc(sizeof(int)*DIM);
         another[i]=(int*)malloc(sizeof(int)*DIM);//10 bytes
            for (j=0; j<DIM; j++){

            matrix [i][j]= 0;
            another [i][j]= 0;

             }
            }

    while (mina_counter < totmine ){


        x= 0 + rand() / (RAND_MAX / ((DIM - 1) - 1 + 1) + 1);//pseudorandom numbers por mines
        y= 0 + rand() / (RAND_MAX / ((DIM - 1) - 1 + 1) + 1);



        if (matrix [x][y]!= MINE){//not repeat
                matrix [x][y]= MINE;
                mina_counter++;
                }

        }
    for (i=0;i<DIM;i++){
        for (j=0;j<DIM;j++){

            if (matrix[i][j]==MINE){//if it is a mine
               ;
                if (i>0 ){
                    if (matrix [i-1][j]!=MINE){
                        matrix [i-1][j]= matrix [i-1][j] + 1;// up from -1
                    }
                }
                if (i<DIM){
                    if (matrix [i+1][j]!=MINE){
                       matrix [i+1][j]= matrix [i+1][j] + 1;// down from -1
                        }
                    }
                if (j>0){
                    if (i>0){
                        if (matrix [i-1][j-1]!=MINE)
                            matrix [i-1][j-1]=matrix [i-1][j-1]+1;//el left up
                            if  (matrix [i][j-1]!=MINE)
                            matrix [i][j-1]=matrix [i][j-1]+1;//behind from -1
                        }
                        if (i<DIM ){
                            if (matrix [i+1][j-1]!=MINE)
                            matrix [i+1][j-1]=matrix [i+1][j-1]+1;//down left
                        }
                    }

                if (j<DIM ){
                    if (i>0){
                        if (matrix [i-1][j+1]!=MINE)
                            matrix [i-1][j+1]=matrix [i-1][j+1]+1;//right up
                        if (matrix [i][j+1]!=MINE)
                            matrix [i][j+1]=matrix [i][j+1]+1;//left from -1
                        }
                    if (i<DIM){
                        if (matrix [i+1][j+1]!=MINE)
                            matrix [i+1][j+1]=matrix [i+1][j+1]+1;//down right
                        }
                     }

            }
        }
    }

    while (1){
       DisplayTable(matrix,another,mineshow) ;

     if (mineshow) {//to finish the game
      break;
    }
    int gcol;
    int status;
    int grow;
    printf("Enter row: ");
    scanf(" %d", &grow);
    printf("Enter column: ");
    scanf("%d", &gcol);

    status = OpenCell(matrix, another,grow,gcol);
    if (almostwon(another)) {
      printf("You have won, Congrats!!\n");
      show (matrix, DIM);
      for (i=0; i<DIM; i++){
         free (matrix[i]);
         free (another[i]);
    }
      free (matrix);
      free (another);

    } else if (status == ALREDY_COORD) {//if you repeat
      printf("Alredy opened cell\n");
    } else if (status == ERROR_MINE_FOUND) {
                printf("You have lost\n");
                showcompletematrix(another);
                mineshow = 1;
                }
       }


    return 1;



}
int OpenCell(int** m, int** a,int r, int c){


    r--;

  int col = c-1;

    if (a[r][col]!=1){//When you find a mine
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

void DisplayTable(int** m, int** a,int ms){
    int i,j,r;
    int col;
    int blanks;


    printf("   ");
    for (i = 0; i < DIM; i++) {
     col=i+1;
    printf ("   %i", col);
    }
    printf("\n");
    r = 1;
    printf(" 1 ");
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            if (m[i][j]!=-1&&a[i][j]==1){//when its not a mine and we have sthwe print the number of matrix in a
                if (m[i][j]!=0){

                    printf(" %3d", m[i][j]);
                }
                else{
                    printf("    ");
                }
            }
            else{if (ms){
                    printf("   X");
                    }else{
                    printf("   #");
                    }
            }
          }
    printf("\n");
    r++;
    if (r<=DIM){
    printf("%2d ", r);//numbers in rows
    }
  }
   for (i = 0; i < ((DIM)*4+4); i++) {
  printf("-");
   }
   printf("\n");
}
