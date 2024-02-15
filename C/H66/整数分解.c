#include <stdio.h>
int main(){
    int x,i=1,mask=1;

    printf("请输入一个自然数\n");
    scanf("%d",&x);
    int xs = x; 

    while(x>9){
        x/=10;
        mask *= 10;
    }
    
    x=xs;
    do{
        int d = x/mask;
        printf("%d",d);
        if(mask>9){
            printf(" ");
        }
        x %= mask;
        mask /= 10;
    }while(mask>0);
    return 0;
}
