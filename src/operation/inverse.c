#include <stdio.h>
#include<stdlib.h>
#include "matrice.h"
#include "matrice2sm.h"



stmat inv2(stmat sm) {
    float det=detsm(sm);
    float temp;
    stmat mi;
    if (sm.d[0] != 2 || sm.d[1]!= 2) {
        printf("Not 2x2\n"); return mi;
    }
    
    if (det==0) {
        printf("N'est pas inversible.\n");
    }
    
    mi=reserversm(2,2);
    mi.m[0][0]=sm.m[1][1]/det;
    mi.m[1][1]=sm.m[0][0]/det;
    mi.m[0][1]=-sm.m[0][1]/det;
    mi.m[1][0]=-sm.m[1][0]/det;
    return mi; 
}



stmat inversesm(stmat M) {
    if (M.d[0]==2 && M.d[1]==2) {
        stmat in=inv2(M);
        return in;
    }
    
    stmat cm;
    float det=detsm(M);
    if (det==0) {
        printf("Not inversible\n");
        cm.m=NULL;
        return cm; // cm.m est null
    }
    
    cm=comatsm(M);
    cm=trasprep(cm);
    
    for(int i=0;i < cm.d[0];i++) {
        for(int j=0;j<cm.d[1];j++) {
            cm.m[i][j]=cm.m[i][j]/det;
        }
    }
    
    return cm;
}