#include <stdio.h>

int main() {
    int x1,x2,x3;
    while (1) {
    printf("=> ");
    scanf("%d %d %d",&x1,&x2,&x3);
    printf("=%d\n",x1*(35)+(-30)*x2+x3*(-25));
    }
    return 0;
}