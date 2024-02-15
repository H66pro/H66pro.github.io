#include <stdio.h>
#include <math.h>
int main(){
    int i,a=1;
    double x=0.0,pi;

    for( i=1; fabs(x)>=1e-6; i+=2){
        pi=x*4;
        x+=a/i;
        a=-a;
    }
    printf("%g",pi);
    return 0;
}