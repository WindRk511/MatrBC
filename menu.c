/**
 * @file menu.c
 * @brief raccourci vers les fonctions
 */

#include <stdio.h>
#include"matrice.h"
int menu() {
    int i=0,choix;
    printf("%d) Produit de matrice\n",++i);
    printf("%d) Trace de matrice\n",++i);
   printf("%d) Determinant\n",++i);
   printf("> ");
    scanf("%d",&choix);
    switch (choix) {
       case 1: produit(); break;
        case 2: trace(); break;
       case 3: deter(); break;
        default : printf("Choix incorrect\n"); break;
        
    }
    return 0;
}