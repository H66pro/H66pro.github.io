#include <stdio.h>

void sum(int begin,int end){
    int sum=0;
    int i;
    for ( i=begin; i<=end; i++){
        sum += i;
    }
    printf("%d到%d的和为%d\n@多吃韩66",begin,end,sum);
}


int main(){
    // void sum(int begin,int end);
    sum(99,250);
    return 0;
}

