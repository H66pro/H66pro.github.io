#include <stdio.h>
int main(){
    int a[10];
    int i;
    for(i=0;i<10;i++){
        a[i]=0;
    }
    int x;
    printf("������0-9����,�ÿո�ֿ�,���Է�Χ���������\n");
    
    do{
        scanf("%d",&x);
        a[x]++;
    }while(x>=0 && x<=9);
    
    for(i=0;i<10;i++){
        printf("%d����%d��\n",i,a[i]);
    }
}