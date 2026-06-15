#ifndef MATRICE2SM_H
#define MATRICE2SM_H

/**
 * @brief structure de Matrice
 */
typedef struct {
    int d[2];  /** dimention indice 0 ligne, 1 colonne */
    float **m; /** matrice */
} stmat;

stmat* cremat(int ligne, int colonne);

/** 
 * @brief reserversm tableau pour matrice
 * @param ligne reserver
 * @param colonne reserver
 * @return structure de matrice
 */
stmat reserversm(int ligne, int colonne);

/**
 * @brief reserver et de remplire le matrice dans le structure
 */
stmat resremsm(int l, int c);

/**
 * @brief liberer le memoire alloé dans le structure
 */
void liberersm(stmat M);

/**
 * @brief afficher le contenu de matrice dans le structure de matrice
 */
void voirsm(stmat sm);

// stmat reserversm(int l, int c);

/**
 * @brief menu pour le produit de matrice
 */
void mproduit();

/**
 * @brief produit de premier argument et le deuxieme
 * @return produit de deux matrice
 */
stmat produit(stmat m1,stmat m2);

/**
 * @brief remplir le matrice
 */
void remplism(stmat stm);

/**
 * @brief calcul determinant
 * @return determinant
 */
float detsm(stmat sm);

/**
 * @brief supprimer ligne et colonne indique dans les parametres sur le matrice M
 * @retrurn matrice extrait
*/
stmat croixsup(stmat Matrice,int ligne, int colonne);

/**
 * transposer la matrice dans l'argument
 * @return matrice transpose
 */
stmat trasposersm(stmat M);

/** 
 * @brief trasposer et liberer le memoire de matrice d'origine
 * @return matrice transposer
 */
stmat trasprep(stmat M);

/**
 * @brief calcul comatrice
 * @return comatrice
 */
stmat comatsm(stmat M);

/** 
 * @brief calculer le coefficient de comatrice d'une colonne indique dans l'argument et mettre dans coef
 * @param sMatrice matrice
 * @param tableau_de_coef dans ce tableau on stock le coefficient de comatrice
 * @param colonne colonne pour le comatrice
 */
void lcomdet(stmat sMatrice, float **tabeau_de_coef, int colonne);

/**
 * @brief inverser la matrice
 */
stmat inversesm(stmat M);

/**
 * @brief inversion de matrice 2x2
 */
stmat inv2(stmat sm);

/**
 * @brief menu pour l'inversion de matrice
 */
void minv() ; 

/**
 * @brief mettre le taille de matrice dans structure de matrice
 * @details l'argument est le return avec la taille definie;
 */
stmat dimdefsm(stmat M);

/**
 * @brief menu de creation de matrice
 */
stmat mmcreat();

/**
 * @brief calcul trace
 */
float tracesm(stmat M); 
stmat sommesm(stmat m1,stmat m2);
stmat soustractionsm(stmat m1,stmat m2);
void msomme(char op);
#endif //MATRICE2SM_H