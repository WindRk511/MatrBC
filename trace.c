/**
 * @file trace.c
 * @brief calcul trace
 */
 
#include <stdio.h>
#include"matrice.h"
#include<stdlib.h>

int trace() {
    int *dim;
    float s=0;
    float **M;
    printf("Entrer le dimention : ");
    dim=dimdef();
    M=remplissage(dim);
    for (int i=0; i<dim[0]; i++) {
        s=s+M[i][i];
    }
    printf("Trace=%g\n",s);
    liberer(M,dim[0],dim[1]);
    free(dim);
    return 0;
}