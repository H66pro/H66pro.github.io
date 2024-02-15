#include <stdio.h>
#include <math.h>

int main(){
    int x=2, i=2, ret=1;

    for( x=2; x<100; x++){
        ret = 1;
        for( i=2; i<=sqrt(x); i++){
            if( x % i == 0){
                ret = 0;
                break;
            }
        }
        if( ret == 1){
            printf("%d\t",x);
        }
    }

    return 0;
}