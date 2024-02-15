#include <stdio.h>
int main(){
    int x;
    int i;
    int isPrime=1;

    scanf("%d",&x);
    
    for(i=2;i<x;i++){
        if(x%i == 0){
            isPrime=0;
            break;
        }
    }
    
    if(isPrime==1){
        printf("%d是素数",x);
    }
    else{
        printf("%d不是素数",x);
    }
    
    return 0;
}
