/**
 * @file menu.c
 * @brief raccourci vers les fonctions
 */

#include <stdio.h>
#include<stdlib.h>
#include"matrice.h"
#include"matrice2sm.h"

stmat mmcreat() {
   stmat m;
   printf("Entrer la taille de matrice : ");
   m=dimdefsm(m);
   
   printf("Entrer les coefficient : \n");
   m=resremsm(m.d[0],m.d[1]);
   
   return m;
}

void minv() {
    stmat M,mi;
    M=mmcreat();
    
    mi=inversesm(M);
    if(mi.m==NULL) { printf("Ne pas inversible\n"); goto liber; }
    
    printf("L'inverse est :\n");
    voirsm(mi);
    
    liber: 
    liberersm(M);
    liberersm(mi);
}

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

void mdeter() {
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

    printf("Entrer les coeffient : \n");
    m=resremsm(dim[0],dim[1]);

    det=detsm(m);
    printf("\n Determinant = %g \n",det);

    liberersm(m);
}

void mtrace() {
    float s=0;
    stmat M;
    
    M=mmcreat();
    
    s=tracesm(M);
    printf("Trace=%g\n",s);
    
    liberersm(M);
}

/** 
 * @brief menu commatrice
 */
void mcomat() {
    stmat M=mmcreat();
    stmat com=comatsm(M);
    
    printf("Comatrice :\n");
    voirsm(com);
    
    liberersm(M); liberersm(com);
    
}