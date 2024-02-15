#include <stdio.h>
int main(){
    int i,num1=0,num2=0;
    for( i=1; i<=100; i++){
        if( i%2 != 0){
            num1 += i;
        }
        else{
            num2 +=i;
        }
    }
    printf("奇数和为%d\n偶数和为%d",num1,num2);
    return 0;
}