#include <stdio.h>
#include "matrice.h"
#include<stdlib.h>
#include "matrice2sm.h"

float codet(float** M, int *dim) {
    int i;
    float S=0;
    int spin;

    if(dim[0]==2) {
        S=M[0][0]*M[1][1]-M[0][1]*M[1][0];
        return S;
    }

    spin=-1;
    for(i=0; i < dim[0]; i++) {
        spin=-spin;
        if(M[i][0]==0) {
            S += 0;
            continue;
        }

        stmat m=reserversm(dim[0]-1,dim[1]-1);
        float *pm;
        int p=0;
        for(int j=0; j< dim[0]; j++) {
           pm=&m.m[p][0];
            for(int k=0; k<dim[1]; k++) {
                if(k==0) { continue;}
                else if(j==i) { p--; break; }
                *pm=M[j][k];
               if (pm+1 == NULL) { break; }
               pm++;
            }

           if (p+1 == m.d[0]) { break; }
           p++;
        }

        S+=M[i][0]*spin*codet(m.m,m.d);
        liberersm(m);
    }

    return S;

}

float detsm(stmat sm) {
    float det=codet(sm.m,sm.d);
    return det;
}

void lcomdet(stmat sm, float **coef, int c) {
    stmat tsm;
    int spin=1;
    if(c%2==0) { spin=-1; }
    
    for(int i=0; i<sm.d[0]; i++) {
        spin=-spin;
            tsm=croixsup(sm,i,c); // supprimmer le ligne i et colonne c
            coef[0][i]=spin*detsm(tsm); // leur coefficient commatrice de chaque ligne de ce colonne
    }
    
}