#include <stdio.h>

int num(int);

int main(){
    int a,x;
    
    a = 656;
    x = num(a);
    
    printf("%d",x);
    
    return 0;
}

int num(int a){
    int x;
    x = (a-1)/5;
    return x;
}