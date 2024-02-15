#include <stdio.h>
int main(){
    int a;
    int digit;
    int ret = 0;
    scanf("%d",&a);
    while(a!=0){        
        digit = a%10;
        printf("%d",digit);     //完全倒序输出
        a /= 10;
        ret = ret*10+digit;     //去除无效0输出
    }
    printf("\n%d\n",ret);
    return 0;
}