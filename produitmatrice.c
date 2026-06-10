/** 
 * @file produitmatrice.c
 * @brief calcule de produit matriciel
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#include "matrice2sm.h"

void mproduit() {
    
    int Nm,i;
    stmat* m,M,temp;
    int dim[2];
    printf("Nombre de matrice : ");
    scanf("%d",&Nm);
    m=malloc(sizeof(stmat)*Nm);
    
    for (i=0; i < Nm; i++ ) {
        printf(">Matrice %d \n", i+1);
        printf("Dimension : ");
        scanf("%d %d",dim,dim+1);
        
        if(i>0 && dim[0] != m[i-1].d[1]) {
            printf("\n!!! %dx%d n'est pas compatible avec %dx%d de matrice precedent\n",dim[0],dim[1],m[i-1].d[0],m[i-1].d[1]);
            printf("Veuiller reentrer,svp\n");
            i--;
            continue;
          }
        
         printf("Entrer les coefficients :\n");
        m[i]=resremsm(*dim,*(dim+1));
    }
    
    
    M=m[0];
    for(i=1; i<Nm; i++) {
        temp=M;
        M=produit(M,m[i]);
       if(i>1) { liberersm(temp); }
    }
    
    printf("\nLe produit est :\n");
    // printf( "de taille %dx%d\n",M.d[0],M.d[1]);
    voirsm(M);
    
    // Liberation de memoire
    for(i=0;i<Nm;i++) {
        liberersm(m[i]);
    }
    liberersm(M);
    free(m);
}

stmat produit(stmat m1,stmat m2) {
    int i,j,k;
    stmat M;
    float S;
  
  //calcule le produit de deux matrice
  M=reserversm(m2.d[0],m2.d[1]);
    for(i=0; i< m1.d[0];i++) {
        for(k=0;k<m2.d[1];k++) {
            S=0;
            for(j=0;j<m2.d[0];j++){
                S=S+m1.m[i][j]*m2.m[j][k];
            }
            M.m[i][k]=S;
        }
    }
  
    return M;
}