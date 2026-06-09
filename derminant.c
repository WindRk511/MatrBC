#include <stdio.h>
#include "matrice.h"
#include<stdlib.h>
#include "matrice2sm.h"

int deter() {
    stmat m;
    float det;
    int dim[2];
    
    do {
        printf("Entrer le dimention : ");
        scanf("%d %d",dim,dim+1);
        if (dim[0]!=dim[1]) {
            printf("\nIl faut matrice carré pour calculer le determinant\n");
        }
    } while (dim[0]!=dim[1]);
    
    printf("Remplie les coeffient : \n");
    m=resremsm(dim[0],dim[1]);
    
    det=codet(m.m,m.d);
    printf("\n Determinant = %g \n",det);
    
    liberersm(m);
    return 0;
}

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