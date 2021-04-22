#include <stdio.h>
#include<stdlib.h>
#include "calc.h"


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
