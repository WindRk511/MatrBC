/** 
 * @file matrice.h
 * @brief en tête des fontions
 */

#include"matrice2sm.h"
#ifndef MATRICE_H
#define MATRICE_H


float codet(float** M, int dim[]);
void mdeter();

/**
 * @brief calcule produit magriciel
 */
// int produit();

/**
 * @brief calcul trace
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
 */
int menu(int n);
void mcomat();
int arganalyse(int argc,char *argv[]);
int compatibilitysm(stmat matrice_1,stmat matrice_2,char operateur);
int compatibility(int* d1,int* d2,char o);
#endif //MATRICE_H

