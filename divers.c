/**
 * @file divers.c
 * @brief divers utilitaire
 */
 
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

int* dimdef() {
    int *dim=malloc(sizeof(int)*2);
    int i=0;
    do {
        if(i>0) { 
            printf("\e[2m Le dimension doit être positif !\n\e[0m");
            printf("Reessayer svp\n : ");
        }
        scanf("%d %d",&dim[0],&dim[1]);
        i++;
    } while(dim[0] <= 0 || dim[1] <=0 );
    return dim;
}