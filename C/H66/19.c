#include <stdio.h>

int age(int a){
    int ret;
    if(a==1){
        ret = 10;
    }
    else{
        ret = age(--a)+2;       //  递归函数(占用多)
    }
    return ret;
}

int main(){
    int a;
    scanf("%d",&a);
    printf("%d",age(a));
    return 0;
}