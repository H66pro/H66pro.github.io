#include <stdio.h>
int main(){
    int a,b;
    int x,sum=0;

    printf("请输入长和宽：");
    scanf("%d %d",&a,&b);

    while(a!=0){
        if(a<b){    //大小判断
            x=a;
            a=b;
            b=x;
        }
        a = a-b;
        sum ++;
    }
    printf("共得到%d个正方形",sum);

    return 0;
}