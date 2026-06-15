#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrice.h"

int arganalyse(int na,char* v[]) {
    char* p;
    int P;
    if (na==1) { return 0; }
    
    for(int i=0; i<na;i++) {
        p=strchr(v[i],'-');
        if(p!=NULL) {
            if(strstr(p,"-p")!=NULL || strstr(p," --produit")!=NULL)
                return 1;
            else if(strstr(p,"-s")!=NULL || strstr(p," --somme")!=NULL)
                return 2;
            else if(strstr(p,"-m")!=NULL || strstr(p," --difference")!=NULL)
                return 3;
            else if(strstr(p,"-t")!=NULL || strstr(p," --trace")!=NULL)
                return 4;
            else if(strstr(p,"-d")!=NULL || strstr(p," --determinant")!=NULL)
                return 5;
            else if(strstr(p,"-i")!=NULL || strstr(p," --inverse")!=NULL)
                return 6;
            else if(strstr(p," -c")!=NULL || strstr(p," --comatrice")!=NULL)
                return 7;
            else { fprintf(stderr,"%s : Parametre invalide \n",p); exit(1); }
        }
    }
    return 0;
}