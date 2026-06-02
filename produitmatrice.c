#include <stdio.h>
#include "matrice.h"

int produit() {
    int i,j,k;
   // const int dmax=10;
    int d1[2],d2[2];
    float **m1,**m2,**m3,S;
  
  // Definition de dimention de matrice
    do {
      printf("Dimention M1 : ");
       scanf("%d %d",&d1[0],&d1[1]);
       printf("Dimention M2 : ");
        scanf("%d %d",&d2[0],&d2[1]);
    } while (d1[1]!=d2[0]);
    
 // Remplisase de coeficient
    printf("Matrice 1 :\n");
    m1=remplissage(d1);
    
    printf("Matrice 2 :\n");
    m2=remplissage(d2);
  
  //calcule le produit de deux matrice
  m3=reserver(d2[0],d2[1]);
    for(i=0; i< d1[0];i++) {
        for(k=0;k<d2[1];k++) {
            S=0;
            for(j=0;j<d2[0];j++){
                S=S+m1[i][j]*m2[j][k];
            }
            m3[i][k]=S;
        }
    }
  
  // Affichage du resultat
    printf("\nVotre Matrice :\n");
    voir(m3,d2);
  
  liberer(m1,d1[0],d1[1]);
  liberer(m2,d2[0],d2[1]);
  liberer(m3,d2[0],d2[1]);
    return 0;
}