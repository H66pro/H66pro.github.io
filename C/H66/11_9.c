#include <stdio.h>
int main(){
    int a[3][3] = { 1,2,3,4,5,6,7,8,9};
    int t;

    for( int i=0; i<3; i++){
        for( int z=0; z<i; z++){
            t = a[i][z];
            a[i][z] = a[z][i];
            a[z][i] = t;
        }
    }
    
    printf("a = ");
    
    for( int i=0; i<3; i++){
        printf("\t");
        for( int z=0; z<3; z++){
            printf("%d\t",a[i][z]);
        }
        printf("\n");
    }
    
    return 0;
}