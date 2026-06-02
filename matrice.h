#ifndef MATRICE_H
#define MATRICE_H
int produit();
int trace();
float** remplissage(int* dimension);
void voir(float** matrice, int* dimension);
float** reserver(int ligne, int colonne);
void liberer(float** matrice, int ligne, int colonne);
#endif //MATRICE_H

