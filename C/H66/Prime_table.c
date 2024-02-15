#include <stdio.h>

int isprime( int , int known[], int );
int main(void){
    int number = 600;
    int prime[number];
    int count=1;
    int i=3;
    prime[0] = 2;
    
    while( count<number){
        if( isprime( i, prime, count)){
            prime[count++] = i;
        }
        i++;
    }
    for ( i=0; i<number; i++){
        printf("%d",prime[i]);
        if( (i+1)%5){
            printf("\t");
        }
        else{
            printf("\n");
        }
    }
    return 0;
}

int isprime( int x, int known[], int count){
    int i;
    int ret = 1;
    for( i=0; i<count; i++){
        if( x%known[i] == 0){
            ret = 0;
            break;
        }
    }
    return ret;
}