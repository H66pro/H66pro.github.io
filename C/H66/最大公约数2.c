#include <stdio.h>
int main(){
    int a,b,c;

    printf("请输入\n");
    scanf("%d %d",&a,&b);
    
    while(a % b !=0){
        c = a%b;
        a = b;       
        b = c;
    }
    printf("最大公约数为%d",c);
    return 0;
}
