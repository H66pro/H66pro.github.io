#include <stdio.h>
int main(){
    int a;
    int digit;
    int ret = 0;
    scanf("%d",&a);
    while(a!=0){        
        digit = a%10;
        printf("%d",digit);     //��ȫ�������
        a /= 10;
        ret = ret*10+digit;     //ȥ����Ч0���
    }
    printf("\n%d\n",ret);
    return 0;
}