#include<stdio.h>
#include<stdlib.h>
#include"matrice.h"

float** remplissage(int* dim) {
    float **M;
    M=reserver(dim[0],dim[1]);
    int i,j;
    for(i=0;i<dim[0];i++) {
        for(j=0;j<dim[1];j++) { scanf("%f",&M[i][j]); }
    }
    return M;
}

void voir(float** M, int* dim) {
    int i,j;
    for(i=0;i<dim[0];i++){
        for(j=0;j<dim[1];j++) {
            if(M[i][j]>=0) {printf(" ");}
            printf("%g  ",M[i][j]);
        }
        printf("\n");
    }
}

float** reserver(int l, int c) {
    float** M;
    M=malloc((sizeof(float*)*l));
    for (int i=0; i<c ;i++)
        M[i]=malloc((sizeof(float)*l));
    return M;
}

void liberer(float** M, int l, int c) {
    for (int i=0; i<c ;i++)
        free(M[i]);
    free(M);
}