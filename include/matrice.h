/** 
 * @file matrice.h
 * @brief en tête des fontions
 */

#include"matrice2sm.h"
#ifndef MATRICE_H
#define MATRICE_H

/**
 * @brief calculer le determinant d'une matrice
 * @param M matrice
 * @param dim dimension de la matrice
 * @return determinant de la matrice
 */
float codet(float** M, int dim[]);

/** 
 * @brief menu pour le calcul determinant
 */
void mdeter();

/**
 * @brief calcule produit magriciel
 */
// int produit();

/**
 * @brief menu pour le calcul trace
 */
void mtrace();

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
void liberer(float** matrice, int ligne);

/**
 * @brief definition de dimention
 * @retur tableau qui contient le dimention
 */
int* dimdef();

/**
 * @brief raccourcie vers à des fonction
 * @details menu principal pour choisir les fonctions
 * @param n choix de l'utilisateur
 */
int menu(int n);

/** 
 * @brief menu pour la comatrice
 */
void mcomat();


int arganalyse(int argc,char *argv[]);

/** 
 * @brief verifier la compatibilité de deux matrice pour une operation donnée
 * @param matrice_1 premiere matrice
 * @param matrice_2 deuxieme matrice
 * @param operateur l'operation à verifier
 * @details l'operation peut etre 'p' pour produit et 's' pour somme
 * @return 1 si les matrice sont compatibles, 0 sinon
 */
int compatibilitysm(stmat matrice_1,stmat matrice_2,char operateur);

/** 
 * @brief verifier la compatibilité de deux dimention pour une operation donnée en donnant les dimention de deux matrice
 * @param d1 dimention de la premiere matrice
 * @param d2 dimention de la deuxieme matrice
 * @param o l'operation à verifier
 * @return 1 si les dimention sont compatibles, 0 sinon
 */
int compatibility(int* d1,int* d2,char o);
#endif //MATRICE_H

