#include <stdio.h>
int main(){
    int a,b;
    int x,sum=0;

    printf("�����볤�Ϳ�");
    scanf("%d %d",&a,&b);

    while(a!=0){
        if(a<b){    //��С�ж�
            x=a;
            a=b;
            b=x;
        }
        a = a-b;
        sum ++;
    }
    printf("���õ�%d��������",sum);

    return 0;
}