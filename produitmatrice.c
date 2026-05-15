#include <stdio.h>

int main() {
    int i,j,k;
    int d1[2],d2[2];
    float m1[10][10],m2[10][10],m3[10][10],S;
    do {
      printf("Dimention M1 : ");
       scanf("%d %d",&d1[0],&d1[1]);
       printf("Dimention M2 : ");
        scanf("%d %d",&d2[0],&d2[1]);
    } while (d1[1]!=d2[0]);
    
    printf("Matrice 1 :\n");
    for(i=0;i<d1[0];i++) {
        for(j=0;j<d1[1];j++) { scanf("%f",&m1[i][j]); }
    }
    
    
    printf("Matrice 2 :\n");
    for(i=0;i<d1[0];i++) {
        for(j=0;j<d1[1];j++) { scanf("%f",&m2[i][j]); }
    }
    
    for(i=0; i< d1[0];i++) {
        for(k=0;k<d2[1];k++) {
            S=0;
            for(j=0;j<d2[0];j++){
                S=S+m1[i][j]*m2[j][k];
            }
            m3[i][k]=S;
        }
    }
    printf("\nVotre Matrice :\n");
    for(i=0;i<d2[0];i++){
        for(j=0;j<d2[1];j++) {
            if(m3[i][j]>=0) {printf(" ");}
            printf("%g  ",m3[i][j]);
        }
        printf("\n");
    }
    return 0;
}
