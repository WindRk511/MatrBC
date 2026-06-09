/**
 * @file trace.c
 * @brief calcul trace
 */
 
#include <stdio.h>
#include"matrice.h"
#include"matrice2sm.h"
#include<stdlib.h>

int trace() {
    int dim[2];
    float s=0;
    stmat M;
    printf("Entrer le dimention : ");
    scanf("%d %d",dim,dim+1);
    
    printf("Remplie votre matrice : \n");
    M=resremsm(dim[0],dim[1]);
    for (int i=0; i<dim[0]; i++) {
        s=s+M.m[i][i];
    }
    printf("Trace=%g\n",s);
    
    liberersm(M);
    return 0;
}