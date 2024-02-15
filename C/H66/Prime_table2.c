#include <stdio.h>

int main(){
    int x,i,a=0;
    int max = 1000;      //  此处修改最大值
    int prime[max]; 
    for( i=0; i<max;i++){
        prime[i] = 1;
    }

    for( x=2; x<max; x++){
        if( prime[x]==0){
            continue;
        }
        for( i=2; i*x<max; i++){
            prime[i*x]=0;   // 0表示不是质数
        }
    }

    for( i=2; i<max; i++){
        
        if(prime[i]){
            printf("%d",i);
            a++;
            
            if( a%5){           //格式语句
            printf("\t");
            }
            else{
            printf("\n");
            }
        }
        
    }
    return 0;
}