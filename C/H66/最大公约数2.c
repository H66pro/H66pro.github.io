#include <stdio.h>
int main(){
    int a,b,c;

    printf("������\n");
    scanf("%d %d",&a,&b);
    
    while(a % b !=0){
        c = a%b;
        a = b;       
        b = c;
    }
    printf("���Լ��Ϊ%d",c);
    return 0;
}
