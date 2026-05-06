#include <stdio.h>

int main() {
    float m1[3],m2[3];
    printf("Vecteur H 1 :\n");
    for (int i = 0; i<3; i++) { scanf("%f",m1+i); }
    printf("Vecteur V 2 :\n");
    float S=0;
    int j=0;
    do {
    for (int i = 0; i<3; i++) {
        scanf("%f",m2+i);
        S=S+(m1[i]*m2[i]);
    }
    
    printf("S=%f\n",S);
        S=0;
    } while (++j<3);
    
    return 0;
}