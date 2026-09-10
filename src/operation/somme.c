/** @file somme de matrice
 */
#include <stdio.h>
#include <stdlib.h>
#include "matrice2sm.h"
#include "matrice.h"

stmat sommesm(stmat m1,stmat m2) {
    stmat M;
    if(compatibility(m1.d,m2.d,'s')<0) {
        printf("%dx%d incompatible avec %dx%d\n",m1.d[0],m1.d[1],m2.d[0],m2.d[1]);
        exit(1);
    }
    
    M.d[0]=m1.d[0];
    M.d[1]=m1.d[1];
    M=reserversm(M.d[0],M.d[1]);
    for(int i=0; i<M.d[0]; i++) {
        for(int j=0; j<M.d[1]; j++) {
            M.m[i][j]=m1.m[i][j]+m2.m[i][j];
        }
    }
    return M;
}

stmat soustractionsm(stmat m1,stmat m2) {
      stmat M;
    if(compatibility(m1.d,m2.d,'s')<0) {
        printf("%dx%d incompatible avec %dx%d\n",m1.d[0],m1.d[1],m2.d[0],m2.d[1]);
        exit(1);
    }
    M.d[0]=m1.d[0];
    M.d[1]=m1.d[1];
    M=reserversm(M.d[0],M.d[1]);
    for(int i=0; i<M.d[0]; i++) {
        for(int j=0; j<M.d[1]; j++) {
            M.m[i][j]=m1.m[i][j]-m2.m[i][j];
        }
    }
    return M;
}