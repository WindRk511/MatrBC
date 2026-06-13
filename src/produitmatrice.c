/** 
 * @file produitmatrice.c
 * @brief calcule de produit matriciel
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#include "matrice2sm.h"


stmat produit(stmat m1,stmat m2) {
    int i,j,k;
    stmat M;
    float S;
    
    if (m1.d[0]<m2.d[0]) {
        i=m1.d[0];
    } else { i=m2.d[0]; }
    
  M=reserversm(i,m2.d[1]);
    
    //calcule le produit de deux matrice
    for(i=0; i< m1.d[0];i++) {
        if (i>m2.d[0]) {continue;}
        for(k=0;k<m2.d[1];k++) {
            S=0;
              if(k>m1.d[0]) { continue;}
            for(j=0;j<m2.d[0];j++){
                S=S+m1.m[i][j]*m2.m[j][k];
            }
          
            M.m[i][k]=S;
        }
    }
  
    return M;
}