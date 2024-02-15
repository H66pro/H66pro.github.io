#include <stdio.h>
int main(){
    int a[10];
    int i;
    for(i=0;i<10;i++){
        a[i]=0;
    }
    int x;
    printf("请输入0-9的数,用空格分开,并以范围外的数结束\n");
    
    do{
        scanf("%d",&x);
        a[x]++;
    }while(x>=0 && x<=9);
    
    for(i=0;i<10;i++){
        printf("%d共有%d个\n",i,a[i]);
    }
}