/**
 * @file divers.c
 * @brief divers utilitaire
 */
 
#include<stdio.h>
#include<stdlib.h>
#include"matrice.h"
#include"matrice2sm.h"

float** reserver(int l, int c) {
    float** M;
    M=malloc((sizeof(float*)*l));
    for (int i=0; i<c ;i++)
        M[i]=malloc((sizeof(float)*l));
    return M;
}

void remplism(stmat stm) {
    float** M;
    int i,j;
    
    if(stm.m==NULL) {
        printf("Le matrice NULL\n");
        exit(1);
    }
    
    M=stm.m;
    for(i=0; i<stm.d[0]; i++) {
        for(j=0; j<stm.d[1]; j++) { scanf("%f",&M[i][j]); }
    }
}

stmat reserversm(int l, int c) {
    stmat sm;
    sm.d[0]=l; sm.d[1]=c;
    sm.m=reserver(l,c);
    return sm;
}

stmat resremsm(int l, int c) {
    stmat sm=reserversm(l,c);
    remplism(sm);
    
    return sm;
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

void voirsm(stmat sm) {
    int i,j;
    float **M=sm.m;
    
    for(i=0;i<sm.d[0];i++){
        for(j=0;j<sm.d[1];j++) {
            if(M[i][j]>=0) {printf(" ");}
            printf("%g  ",M[i][j]);
        }
        printf("\n");
    }
}

void liberer(float** M, int l, int c) {
    for (int i=0; i<c ;i++)
        free(M[i]);
    free(M);
}

void liberersm(stmat M) {
    liberer(M.m,M.d[0],M.d[1]);
}



