#ifndef MATRICE2SM_H
#define MATRICE2SM_H

typedef struct {
    int d[2];
    float **m;
} stmat;

stmat* cremat(int ligne, int colonne);
stmat reserversm(int l, int c);
void liberersm(stmat M);
void voirsm(stmat sm);
stmat resremsm(int l, int c);
stmat reserversm(int l, int c);
void mproduit();
stmat produit(stmat m1,stmat m2);
void remplism(stmat stm);
float detsm(stmat sm);
stmat croixsup(stmat M,int li, int cl);
stmat trasposersm(stmat M);
stmat trasprep(stmat M);
stmat comatsm(stmat M);
void lcomdet(stmat sm, float **coef, int c);
stmat inversesm(stmat M);
void minv() ; // menu de l'inverse
stmat dimdefsm(stmat M);
stmat inv2(stmat sm);
stmat mmcreat();
float tracesm(stmat M); 

#endif //MATRICE2SM_H