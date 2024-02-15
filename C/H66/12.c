#include <stdio.h>
int main(){
    int a[3][2] = {5,9,8,0,66,33};
    int t1 ,t2;
    for( int z=1;z<3;z++){
        for( int i=1; i<2;i++){
            if( a[t1][t2]>a[z][i]){
                t1 = z;
                t2 = i;
            }
        }
    }
    // for( int z=0;z<3;z++){
    //     for( int i=0; i<2;i++){
    //        printf("%d",a[z][i]);
    //     }
    //     printf("\n");
    // }
    printf("a[%d][%d]=%d",t1,t2,a[t1][t2]);
    return 0;
}