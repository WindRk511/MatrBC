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
#endif //MATRICE2SM_H