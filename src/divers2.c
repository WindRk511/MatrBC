/**
 * @file duvers2.c
 * @brief outil supplementaire 
 */
 
#include <stdio.h>
#include"matrice.h"
#include"matrice2sm.h"
#include<stdlib.h>

// calcul trace
float tracesm(stmat M) {
    float s;
    int dim=M.d[0];
    if(M.d[0]>M.d[1]) { dim=M.d[1];}
    for (int i=0; i<dim; i++) {
        s=s+M.m[i][i];
    }
    return s;
}

// transposeur de matrice
stmat trasposersm(stmat M) {
    float temp;
    stmat trs=reserversm(M.d[1],M.d[0]);
    for(int i=0; i<M.d[0];i++) {
        for(int j=0; j<M.d[1]; j++) {
            trs.m[j][i]=M.m[i][j];
        }
    }
    return trs;
}

// trasposé pour remplacer
stmat trasprep(stmat M) {
    stmat tma=trasposersm(M);
    liberersm(M);
    return tma;
}

//comatrice
stmat comat2sm(stmat M) {
    stmat m=reserversm(M.d[0],M.d[1]);
    m.m[0][0]=M.m[1][1];
    m.m[0][1]=-M.m[1][0];
    m.m[1][0]=-M.m[0][1];
    m.m[1][1]=M.m[2][2];
    return m;
}
stmat comatsm(stmat M) {
    stmat cm;
    if (M.d[0]==2 && M.d[1]==2) {
        cm=comat2sm(M);
        return cm;
    }
    
    cm=reserversm(M.d[0],M.d[1]);
    float* lcom=malloc(sizeof(float)*M.d[0]);
    
    for(int i=0; i<M.d[1];i++) {
        lcomdet(M,&lcom,i);
        for(int j=0; j< M.d[0]; j++) { 
            cm.m[j][i]=lcom[j];
        }
    }
    return cm;
}


