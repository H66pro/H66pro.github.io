#include <stdio.h>
#include <math.h>

int main(){
    int i,x,ret=1;

    for( x=100;x<=200;x++,ret=1){
        if( x%2==0 && x!=2){
            continue;
        }
        for( i=3; i<=sqrt(x); i++){
            if( x%i==0){
                ret = 0;
                break;
            }
        }
        if( ret==1){
            printf("%d\t",x);
        }
    }
    return 0;
}