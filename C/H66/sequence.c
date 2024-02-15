#include <stdio.h>

int main(){
    int num[] = { 8,7,1,6,88,14,75,94,14,75,24,63,74,11,19,17,13};
    int len = sizeof(num)/sizeof(num[0]);
    int t=0,x;
    int i,z; 
    for(  i=0; i<len; i++){
        printf("%d\t",num[i]);
    }
    for(  i=1; i<len; i++){
        t = i-1;
        for ( z=i; z<len; z++){
            if( num[t]> num[z]){
                t = z;
            }
        }
        x = num[i-1];
        num[i-1] = num[t];
        num[t] = x;
    }
    
    for(  i=0; i<len; i++){
        printf("%d\t",num[i]);
    }
    // printf("%p",num);
    return 0;
}
