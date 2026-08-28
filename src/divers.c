/**
 * @file divers.c
 * @brief divers utilitaire
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"matrice.h"
#include"matrice2sm.h"

float** reserver(int l, int c) {
    float** M;
    M=malloc((sizeof(float*)*l));
    for (int i=0; i< l ;i++)
        M[i]=malloc((sizeof(float)*c));
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
            if(M[i][j]>=0) { printf(" "); }
            printf("%g  ",M[i][j]);
        }
        printf("\n");
    }
}

void liberer(float** M, int ligne) {
    for (int i=0; i<ligne ;i++)
        free(M[i]);
    free(M);
}

void liberersm(stmat M) {
    liberer(M.m,M.d[0]);
}

stmat croixsup(stmat M,int li, int cl) {
    stmat m=reserversm(M.d[0]-1,M.d[1]-1);
        float *pm;
        int p=0;
        for(int j=0; j< M.d[0]; j++) {
           pm=&m.m[p][0];
            for(int k=0; k<M.d[1]; k++) {
                if(k==cl) { continue;}
                else if(j==li) { p--; break; }
                *pm=M.m[j][k];
               if (pm+1 == NULL) { break; }
               pm++;
            }

           if (p+1 == m.d[0]) { break; }
           p++;
        }
    return m;
}

stmat dimdefsm(stmat M) {
    char c[6];
    while(getchar()!='\n');
    fgets(c,5,stdin);
    printf("%s\n",c);
    if(strchr(c,'x')!=NULL)
      sscanf(c, "%dx%d",&M.d[0],&M.d[1]);
    else 
        sscanf(c, "%d %d",&M.d[0],&M.d[1]);
    
    if(M.d[0]==0 || M.d[1]==0) {
        printf("Dimension %dx%d est non valide.\n",M.d[0],M.d[1]);
        printf("Reentrer svp : ");
        M=dimdefsm(M);
    }
    
    return M;
}

int compatibility(int* d1,int* d2,char o) {
   
    switch (o) {
          // compatibilité sur produit
        case 'p':
        if(d1[0]!=d2[1]) {
            return -1;
        } else return 1;
        break;
        
          // compatibilité sur somme
        case 's':
        if(d1[0]!=d2[0] || d1[1]!=d2[1]) {
            return -1;
        } else return 1;
        break;
        default: printf("Operateur non disponible"); return 0; break;
        
    }
    return 1;
}


    
    

