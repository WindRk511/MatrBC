/**
 * @file menu.c
 * @brief raccourci vers les fonctions
 */

#include <stdio.h>
#include<stdlib.h>
#include"matrice.h"
#include"matrice2sm.h"

//menu de creation de matrice
stmat mmcreat() {
   stmat m;
   printf("Entrer la taille de matrice : ");
   m=dimdefsm(m);
   
   printf("Entrer les coefficient : \n");
   m=resremsm(m.d[0],m.d[1]);
   
   return m;
}

//menu de creation de matrice
stmat mmcreatc(int* d, char op) {
   stmat m;
   int i=0;
   while(i==0) {
      printf("Entrer la taille de matrice : ");
      m=dimdefsm(m);
      if(op == 's') {
         if(compatibility(d,m.d,op)!=1) {
            printf("%dx%d incompatible avec %dx%d\n",d[0],d[1],m.d[0],m.d[1]);
            printf("Ressayer svp\n"); continue;
         }
      }
      else if(op == 'p') {
         if(compatibility(d,m.d,op)!=1) {
            printf("%dx%d incompatible avec %dx%d\n",d[0],d[1],m.d[0],m.d[1]);
            printf("Ressayer svp\n"); continue;
         }
      }
      else  { fprintf(stderr,"Operateur non definie\n"); exit(1); }
    i++;  
   };
   
   printf("Entrer les coefficient : \n");
   m=resremsm(m.d[0],m.d[1]);
   
   return m;
}

//menu de l'inverse
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

//menu de produit
void mproduit() {
    int Nm,i;
    stmat* m,M,temp;
    int dim[2];
    
    printf("Nombre de matrice : ");
    scanf("%d",&Nm);
    m=malloc(sizeof(stmat)*Nm);
    
    for (i=0; i < Nm; i++ ) {
        printf(">Matrice %d \n", i+1);
        if(i==0) { m[i]=mmcreat(); continue;}
        m[i]=mmcreatc(m[i-1].d,'p');
    }
    
    M=m[0];
    for(i=1; i<Nm; i++) {
        temp=M;
        M=produit(M,m[i]);
       if(i>1) { liberersm(temp); }
    }
    
    printf("\nLe produit est :\n");
    voirsm(M);
    
    // Liberation de memoire
    for(i=0;i<Nm;i++) {
        liberersm(m[i]);
    }
    liberersm(M);
    free(m);
}

// menu calcul determinant
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

// menu trace
void mtrace() {
    float s=0;
    stmat M;
    
    M=mmcreat();
    
    s=tracesm(M);
    printf("Trace=%g\n",s);
    
    liberersm(M);
}

/** 
 * @brief menu comatrice
 */
void mcomat() {
    stmat M=mmcreat();
    stmat com=comatsm(M);
    
    printf("Comatrice :\n");
    voirsm(com);
    
    liberersm(M); liberersm(com);
    
}

void msomme(char op) {
   stmat m,S,smtemp;
   int i,Nm,d[2];
   
   printf("Entrer le nombre de matrice : ");
   scanf("%d",&Nm);
   printf("Entrer la taille de ces matrices : ");
   scanf("%d %d",d,d+1);
   
   
   for(i=0; i < Nm;i++) {
     printf("Matrice %d:\n",i+1);
      m=resremsm(*d,*(d+1));
      
      if(i<1) { S=m; continue; }
      smtemp=S;
      if(op=='+')
      S=sommesm(S,m);
      else if (op=='-')
      S=soustractionsm(S,m);
      liberersm(smtemp);
      liberersm(m);
   }
   
   switch (op){
      case '+': printf("La somme :\n"); break;
      case '-': printf("La differencr :\n"); break;
      default: break;
   }
   voirsm(S);
   liberersm(S);
}

