#include <stdio.h>
#include<stdlib.h>
#include "calc.h"
#define DIM 10


void showcompletematrix(int** a)  {
  int i, j,c;
  int w=1;

  printf("   ");
    for (i = 0; i < DIM; i++) {

        for (j = 0; j < DIM; j++) {
            a[i][j]=1;
        }
    }
}