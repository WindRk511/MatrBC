/**
 * @file menu.c
 * @brief raccourci vers les fonctions
 */

#include <stdio.h>
#include"matrice.h"
#include"matrice2sm.h"

int menu(int choix) {
    int i=0;
   if(choix == 0) {
      printf("%d) Produit de matrice\n",++i);
      printf("%d) Somme\n",++i);
      printf("%d) Difference\n",++i);
      printf("%d) Trace de matrice\n",++i);
      printf("%d) Determinant\n",++i);
      printf("%d) Inverse\n",++i);
      printf("%d) comatrice\n",++i);
      printf("> ");
      scanf("%d",&choix);
   }
    switch (choix) {
       case 1: mproduit(); break;
       case 2: msomme('+'); break;
       case 3: msomme('-'); break;
       case 4: mtrace(); break;
       case 5: mdeter(); break;
       case 6: minv(); break;
       case 7: mcomat(); break;
       default : printf("Choix incorrect\n"); menu(0); break;
    }
    return 0;
}

