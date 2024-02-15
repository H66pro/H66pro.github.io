#include <stdio.h>
#include <string.h>
int main(){
    
    for( int i=1;i<=4;i++){
        for( int k=1; k<=4-i; k++){
            printf(" ");
        }
        for( int z=1; z<=i*2-1; z++){
            printf("*");
        }
        printf("\n");
    }
    for( int i=1; i<=3; i++){
        for( int k=1; k<=i; k++){
            printf(" ");
        }
        for( int z=1; z<=7-i*2; z++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}