#include<stdio.h>
int zdGYS(int a ,int b);
int zxGBS(int a,int b);

int main(){
    int x,y;
    
    scanf("%d %d",&x,&y);
    printf("%d��%d�����Լ��Ϊ%d\n",x,y,zdGYS(x,y));
    printf("%d��%d����С������Ϊ%d\n",x,y,zxGBS(x,y));

    return 0;
}

int zdGYS(int a ,int b){
    int i,ret;
    i = a>b?b:a;
    printf("i = %d\n",i);
    for( ; i>0; i--){
        if( a%i == 0 && b%i ==0){
            ret = i;
            break;
        }
    }
    return ret;
}

int zxGBS(int a,int b){
    int ret;
    ret = a * b / zdGYS( a, b);
    return ret;
}