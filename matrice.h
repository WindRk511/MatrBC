/** 
 * @file matrice.h
 * @brief en tête des fontions
 */

#ifndef MATRICE_H
#define MATRICE_H

typedef struct {
    int d[2];
    float **m;
} stmat;

stmat* cremat(int ligne, int colonne);
float codet(float** M, int dim[]);
int deter();
stmat reserversm(int l, int c);
void liberersm(stmat M);

/**
 * @brief calcule produit magriciel
 */
int produit();

/**
 * @brief calcul trace
 */
int trace();

/**
 * @brief remplissage des coefficients de matrice
 * @param dimention tableau de dimention
 * @return matrice remplie
 */
float** remplissage(int* dimension);

/**
 * @brief voir affiche la matrice
 * @param matrice tableau de 2 dimention
 * @param dimention
 */
void voir(float** matrice, int* dimension);

/**
 * @brief reserve tableau de deux dimention
 * @param ligne nombre de ligne
 * @param colone nombre de colonne
 * @return tableau reservé
 */
float** reserver(int ligne, int colonne);

/**
 * @brief liberer tableau de deux dimention
 * @param tableau reservé
 * @param ligne nombre de ligne
 * @param colone nombre de colonne
 */
void liberer(float** matrice, int ligne, int colonne);

/**
 * @brief definition de dimention
 * @retur tableau qui contient le dimention
 */
int* dimdef();

/**
 * @brief raccourcie vers à des fonction
 */
int menu();
#endif //MATRICE_H

